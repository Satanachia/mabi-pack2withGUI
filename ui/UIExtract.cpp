#include "UIExtract.h"
#include "ui_UIExtract.h"
#include <QFileDialog>

UIExtract::UIExtract(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UIExtract)
{
    ui->setupUi(this);
    dll_Import_Mgr mgr;
    mgr.loadExtractFun(m_extract);
}

UIExtract::~UIExtract()
{
    delete ui;
}

void UIExtract::on_fromBtn_clicked()
{
    QString cachePath = MabiGlobal::g_setting.value("file_path").toString();
    QFileDialog* file = new QFileDialog(this, "选择要解包的it文件", cachePath, "it files(*.it)");
    if  (file->exec() == QFileDialog::Accepted){
        QString path = file->selectedFiles().at(0);
        MabiGlobal::g_setting.setValue("file_path", path);
        ui->fromTxt->setText(path);
    }
}


void UIExtract::on_toBtn_clicked()
{
    QString cacheDir = MabiGlobal::g_setting.value("extract_dir").toString();
    QString filePath = QFileDialog::getExistingDirectory(this, "将文件解包至...", cacheDir);
    if (filePath != ""){
        MabiGlobal::g_setting.setValue("extract_dir", filePath);
        ui->toTxt->setText(filePath);
    }
}


void UIExtract::on_execBtn_clicked()
{
    QString from = ui->fromTxt->text();
    QString to = ui->toTxt->text();
    if (from.isEmpty()) return;
    QFile fromPath(from);
    if (!fromPath.exists()) return;
    QDir toPath (to);
    if (!toPath.exists()){
        to = "./";
    }
    m_extract(from.toUtf8().data(), to.toUtf8().data());
    QDesktopServices::openUrl(QUrl::fromLocalFile(to));
}


void UIExtract::on_cancBtn_clicked()
{
    close();
}

