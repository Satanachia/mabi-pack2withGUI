#ifndef UIEXPLORER_H
#define UIEXPLORER_H

#include <QMainWindow>
#include "dll_import_mgr.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include <QStandardItemModel>
#include "MabiFileTreeView.h"
#include "MabiGlobal.h"
#include "readfromweburl.h"
#include "getMabiLog.h"
#include <QPushButton>
#include <QMenu>
#include "UIAbout.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UIExplorer; }
QT_END_NAMESPACE

QString getPath(QModelIndex tn);

class UIExplorer : public QMainWindow
{
    Q_OBJECT

public:
    UIExplorer(QWidget *parent = nullptr);
    ~UIExplorer();
    void closeEvent(QCloseEvent *e);

private slots:
    void on_actionopen_it_file_triggered();
    void on_actionopen_folder_triggered();

    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_actionAbout_this_program_triggered();

signals:

private:
    Ui::UIExplorer *ui;
    EXTRACT m_extract;
    EX_CERTAIN m_ex_certain;
    READ m_read;
    QStandardItemModel* m_model = new QStandardItemModel();
    //声明动作
    QAction* m_extract_to;
    //声明菜单
    QMenu* m_lableMenu;
};
#endif // UIEXPLORER_H
