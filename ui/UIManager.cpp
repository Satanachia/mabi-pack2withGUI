#include "UIManager.h"
#include "ui_UIManageranager.h"

UIManager::UIManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIManager)
{
    ui->setupUi(this);
}

UIManager::~UIManager()
{
    delete ui;
}
