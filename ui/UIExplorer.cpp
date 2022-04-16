#include "UIExplorer.h"
#include "ui_UIExplorer.h"

void getChildren(QStandardItem&, QString&);

UIExplorer::UIExplorer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UIExplorer)
{
    ui->setupUi(this);
    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    dll_Import_Mgr mgr;
    mgr.loadExtractFun(m_extract);
    mgr.loadReadFun(m_read);
    mgr.loadExCertainFun(m_ex_certain);

    //初始化动作
    m_extract_to = new QAction("解压至...",this);

    //初始化菜单
    m_lableMenu = new QMenu(this);

    //动作添加到菜单
    m_lableMenu->addAction(m_extract_to);

    //给动作设置信号槽
    connect( m_extract_to, &QAction::triggered, [=]()
    {
        QString cacheDir = MabiGlobal::g_setting.value("extract_dir").toString();
        QString filePath = QFileDialog::getExistingDirectory(this, "将文件解包至...", cacheDir);
        if (filePath != ""){
            MabiGlobal::g_setting.setValue("extract_dir", filePath);
            auto item = m_model->itemFromIndex(this->ui->treeView->currentIndex());
            QString files;
            if (item->hasChildren()){
                getChildren(*item, files);
            }
            else{
                files = getPath(this->ui->treeView->currentIndex());
            }
            qDebug() << windowTitle();
            m_ex_certain(windowTitle().toUtf8().data(), files.toUtf8().data(), filePath.toUtf8().data());
            QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
        }
    });

    connect(ui->treeView,&QTreeView::customContextMenuRequested,[=]()
    {
        m_lableMenu->exec(QCursor::pos());
    });

}

UIExplorer::~UIExplorer()
{
    delete m_model;
    delete m_extract_to;
    delete m_lableMenu;
    delete ui->treeView;
    delete ui->textBrowser;
    delete ui;
}

void UIExplorer::on_actionopen_it_file_triggered()
{
    QString cachePath = MabiGlobal::g_setting.value("file_path").toString();
    QFileDialog* file = new QFileDialog(this, "选择要查看/解包的it文件", cachePath, "it files(*.it)");
    if  (file->exec() == QFileDialog::Accepted){
        ui->treeView->reset();
        m_model->clear();
        QString path = file->selectedFiles().at(0);
        MabiGlobal::g_setting.setValue("file_path", path);
        MabiFileTreeView helper;
        helper.getFileTreeView(*m_model, path);
        ui->treeView->setHeaderHidden(true);
        ui->treeView->setModel(m_model);
        this->setWindowTitle(path);
    }
}


void UIExplorer::on_actionopen_folder_triggered()
{
    QString cacheDir = MabiGlobal::g_setting.value("file_dir").toString();
    QString filePath = QFileDialog::getExistingDirectory(this, "请选择要查看/解包的文件夹", cacheDir);
    if (filePath != ""){
        MabiGlobal::g_setting.setValue("file_dir", filePath);
    }
    ui->treeView->reset();
    m_model->clear();
    MabiFileTreeView helper;
    helper.getDirTreeView(*m_model, filePath);
    ui->treeView->setHeaderHidden(true);
    ui->treeView->setModel(m_model);
    this->setWindowTitle(filePath);
}


QString getPath(QModelIndex tn)
{
    QString r = tn.data().toString();
    while (tn.parent() != QModelIndex())
    {
        tn = tn.parent();
        r = tn.data().toString() + "/" + r;
    }
    return r;
}

void UIExplorer::on_treeView_doubleClicked(const QModelIndex &index)
{
    if (index.data().toString().contains(".xml") || index.data().toString().contains(".txt"))
    {
        QString file = getPath(index);
        if (MabiGlobal::g_fileCache.find(file) != MabiGlobal::g_fileCache.end() || MabiGlobal::g_fileCache.find(file.replace("/", "\\")) != MabiGlobal::g_fileCache.end())
        {
            auto content = m_read(MabiGlobal::g_fileCache[file]->getDocPath().toUtf8().data(), MabiGlobal::g_fileCache[file]->getFilePath().toUtf8().data());
            ui->textBrowser->setText(QString(content));
#ifndef QT_DEBUG
    delete [] content;
#endif
        }
    }
}


void UIExplorer::on_actionAbout_this_program_triggered()
{
    UIAbout *ab_ui = new UIAbout();
    ab_ui->setAttribute(Qt::WA_DeleteOnClose);
    ab_ui->show();
}

void UIExplorer::closeEvent(QCloseEvent *e){
    delete this;
}

void getChildren(QStandardItem& item, QString& files){
    int rows = item.rowCount();
    for (int i = 0; i < rows; ++i)
    {
        auto child = item.child(i);
        if (child->hasChildren()){
            getChildren(*child, files);
        }
        else
        {
            files += getPath(child->index()) + ";";
        }
    }
}
