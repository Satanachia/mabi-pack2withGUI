#include "UIPack.h"
#include "ui_UIPackpack.h"

UIPack::UIPack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UIPack)
{
    ui->setupUi(this);
    dll_Import_Mgr mgr;
    mgr.loadPackFun(m_pack);
    m_nameui->setAttribute(Qt::WA_DeleteOnClose);
    m_nameui->setAttribute(Qt::WA_ShowModal, true);
    connect(m_nameui, &UIName::emitName,this, &UIPack::getName);
}

UIPack::~UIPack()
{
    delete ui;
}

void UIPack::on_fromBtn_clicked()
{
    QString cacheDir = MabiGlobal::g_setting.value("packfrom_dir").toString();
    QString filePath = QFileDialog::getExistingDirectory(this, "请选择要打包的 data 文件夹", cacheDir);
    if (filePath != ""){
        MabiGlobal::g_setting.setValue("packfrom_dir", filePath);
        ui->fromTxt->setText(filePath);
    }
}


void UIPack::on_toBtn_clicked()
{
    QString cacheDir = MabiGlobal::g_setting.value("packto_dir").toString();
    QString filePath = QFileDialog::getExistingDirectory(this, "请选择输出文件夹", cacheDir);
    if (filePath != ""){
        MabiGlobal::g_setting.setValue("packto_dir", filePath);
        ui->toTxt->setText(filePath);
    }
}


void UIPack::on_execBtn_clicked()
{
    m_from = ui->fromTxt->text();
    if (!ui->toTxt->text().isEmpty())
    {
        m_to = ui->toTxt->text();
    }
    if (m_from.isEmpty())
    {
        QMessageBox::information(nullptr, "警告", "未选择要打包的文件夹.", QMessageBox::Ok);
    }
    else
    {
        m_nameui->show();
    }
}


void UIPack::on_cancBtn_clicked()
{
    close();
}

void UIPack::getName(QString name)
{
    QString desFile = m_to + "/" + name + ".it";
    m_pack(m_from.toUtf8().data(), desFile.toUtf8().data());
    QDesktopServices::openUrl(QUrl::fromLocalFile(m_to));
}

