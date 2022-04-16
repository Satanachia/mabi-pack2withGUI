#include "UIMainWindow.h"
#include "ui_UIMainWindow.h"

UIMainWindow::UIMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIMainWindow)
{
    ui->setupUi(this);
}

UIMainWindow::~UIMainWindow()
{
    delete ui;
}

void UIMainWindow::on_explorerBtn_clicked()
{
    UIExplorer* ui = new UIExplorer();
    ui->setAttribute(Qt::WA_DeleteOnClose);
    ui->show();
}


void UIMainWindow::on_packBtn_clicked()
{
    UIPack* ui = new UIPack();
    ui->setAttribute(Qt::WA_DeleteOnClose);
    ui->show();
}


void UIMainWindow::on_extractBtn_clicked()
{
    UIExtract* ui = new UIExtract();
    ui->setAttribute(Qt::WA_DeleteOnClose);
    ui->show();
}


void UIMainWindow::on_managerBtn_clicked()
{
    UIManager* ui = new UIManager();
    ui->setAttribute(Qt::WA_DeleteOnClose);
    ui->show();
}


void UIMainWindow::on_action_3_triggered()
{
    UISettings* ui = new UISettings();
    ui->setAttribute(Qt::WA_DeleteOnClose);
    ui->show();
}


void UIMainWindow::on_action_2_triggered()
{
    UIAbout* ui = new UIAbout();
    ui->setAttribute(Qt::WA_DeleteOnClose);
    ui->show();
}


void UIMainWindow::on_action_triggered()
{
    QMessageBox::information(nullptr, "提醒", "你已经被强化了.", QMessageBox::Ok);
}

