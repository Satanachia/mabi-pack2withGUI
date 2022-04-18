#include "UIManager.h"
#include "ui_UIManageranager.h"

UIManager::UIManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIManager)
{
    ui->setupUi(this);
    QMap<QString, int> mods;
    MabiModManager modManager;
    modManager.getMabiMods(mods);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableWidget->setRowCount(mods.count());
    QStringList headerText;
    headerText<<"Patch Version"<<"Mod Name"<<"State";
    ui->tableWidget->setHorizontalHeaderLabels(headerText);


    // 设置右键单独更新
    m_update = new QAction("更新",this);
    m_lableMenu = new QMenu(this);
    m_lableMenu->addAction(m_update);
    connect( m_update, &QAction::triggered, [=]()
    {
        qDebug() << "i'm clicked";
    });

    connect(ui->tableWidget,&QTableWidget::customContextMenuRequested,[=]()
    {
        m_lableMenu->exec(QCursor::pos());
    });

}

UIManager::~UIManager()
{
    delete ui;
}
