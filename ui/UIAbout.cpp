#include "UIAbout.h"
#include "ui_UIAbout.h"

UIAbout::UIAbout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UIAbout)
{
    ui->setupUi(this);
}

UIAbout::~UIAbout()
{
    delete ui;
}

void UIAbout::on_pushButton_clicked()
{
    this->close();
}

