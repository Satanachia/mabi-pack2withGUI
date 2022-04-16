#ifndef UIABOUT_H
#define UIABOUT_H

#include <QWidget>
#include "MabiGlobal.h"

namespace Ui {
class UIAbout;
}

class UIAbout : public QWidget
{
    Q_OBJECT

public:
    explicit UIAbout(QWidget *parent = nullptr);
    ~UIAbout();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UIAbout *ui;
};

#endif // UIABOUT_H
