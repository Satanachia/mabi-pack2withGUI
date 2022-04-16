#ifndef UIMAINWINDOW_H
#define UIMAINWINDOW_H

#include <QMainWindow>
#include "UIExplorer.h"
#include "UIAbout.h"
#include "UIPack.h"
#include "UIExtract.h"
#include "UIManager.h"
#include "UISettings.h"
#include "MabiGlobal.h"

namespace Ui {
class UIMainWindow;
}

class UIMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIMainWindow(QWidget *parent = nullptr);
    ~UIMainWindow();

private slots:
    void on_explorerBtn_clicked();

    void on_packBtn_clicked();

    void on_extractBtn_clicked();

    void on_managerBtn_clicked();

    void on_action_3_triggered();

    void on_action_2_triggered();

    void on_action_triggered();

private:
    Ui::UIMainWindow *ui;
};

#endif // UIMAINWINDOW_H
