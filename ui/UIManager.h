#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <QMainWindow>
#include "MabiGlobal.h"

namespace Ui {
class UIManager;
}

class UIManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIManager(QWidget *parent = nullptr);
    ~UIManager();

private:
    Ui::UIManager *ui;
};

#endif // UIMANAGER_H
