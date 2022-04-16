#include "UIName.h"
#include "ui_UIName.h"

UIName::UIName(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UIName)
{
    ui->setupUi(this);
}

UIName::~UIName()
{
    delete ui;
}

void UIName::on_pushButton_clicked()
{
    bool isNum;
    int verNum = ui->verTxt->text().toInt(&isNum);
    QString main = ui->mainTxt->text();
    if (main.isEmpty()) QMessageBox::information(nullptr, "警告", "文件名为空.", QMessageBox::Ok);
    else if (main[0] < 'd') QMessageBox::information(nullptr, "警告", "文件名起始字符小于 'd'， 文件将不会生效.", QMessageBox::Ok);
    else if (main.contains("_")) QMessageBox::information(nullptr, "警告", "文件名不可包含下划线.", QMessageBox::Ok);
    else if (!isNum) QMessageBox::information(nullptr, "警告", "文件版本号非数字.", QMessageBox::Ok);
    else if (ui->verTxt->text().isEmpty()) QMessageBox::information(nullptr, "警告", "文件版本号为空.", QMessageBox::Ok);
    else{
        QString name = main + "_" + ui->verTxt->text();
        emit emitName(name);
        close();
    }
}

