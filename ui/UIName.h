#ifndef UINAME_H
#define UINAME_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class UIName;
}

class UIName : public QWidget
{
    Q_OBJECT

public:
    explicit UIName(QWidget *parent = nullptr);
    ~UIName();

signals:
    void emitName(QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::UIName *ui;
};

#endif // UINAME_H
