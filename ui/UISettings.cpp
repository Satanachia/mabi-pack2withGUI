#include "UISettings.h"
#include "ui_UISettings.h"

UISettings::UISettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UISettings)
{
    ui->setupUi(this);
    ui->gtxt->setText(MabiGlobal::g_setting.value("game_path").toString());
    ui->ptxt->setText(MabiGlobal::g_setting.value("package_path").toString());
    ui->ltxt->setText(MabiGlobal::g_setting.value("log_path").toString());
}

UISettings::~UISettings()
{
    delete ui;
}

void UISettings::on_gamePath_clicked()
{
    QString cacheDir = MabiGlobal::g_setting.value("game_path").toString();
    QString filePath = QFileDialog::getExistingDirectory(this, "请选择游戏路径", cacheDir);
    if (filePath != ""){
        //MabiGlobal::g_setting.setValue("game_path", filePath);
        ui->gtxt->setText(filePath);
    }
}

void UISettings::on_packPath_clicked()
{
    QString cacheDir = MabiGlobal::g_setting.value("package_path").toString();
    QString filePath = QFileDialog::getExistingDirectory(this, "请选择package路径", cacheDir);
    if (filePath != ""){
        ui->ptxt->setText(filePath);
    }
}

void UISettings::on_logPath_clicked()
{
    QString cacheDir = MabiGlobal::g_setting.value("log_path").toString();
    QString filePath = QFileDialog::getExistingDirectory(this, "请选择log路径", cacheDir);
    if (filePath != ""){
        ui->ltxt->setText(filePath);
    }
}

void UISettings::on_okBtn_clicked()
{
    if (ui->gtxt->text() != "")
    {
        MabiGlobal::g_setting.setValue("game_path", ui->gtxt->text());
    }
    if (ui->ptxt->text() != "")
    {
        MabiGlobal::g_setting.setValue("package_path", ui->ptxt->text());
    }
    if (ui->ltxt->text() != "")
    {
        MabiGlobal::g_setting.setValue("log_path", ui->ltxt->text());
    }
    close();
}

