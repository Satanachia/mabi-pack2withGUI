#ifndef UIPACK_H
#define UIPACK_H

#include <QWidget>
#include "MabiGlobal.h"
#include <QFileDialog>
#include "UIName.h"

namespace Ui {
class UIPack;
}

class UIPack : public QWidget
{
    Q_OBJECT

public:
    explicit UIPack(QWidget *parent = nullptr);
    ~UIPack();

private slots:
    void on_fromBtn_clicked();
    void on_toBtn_clicked();
    void on_execBtn_clicked();
    void on_cancBtn_clicked();
    void getName(QString);

private:
    Ui::UIPack *ui;
    PACK m_pack;
    UIName* m_nameui = new UIName();
    QString m_from;
    QString m_to = "./";
};

#endif // UIPACK_H
