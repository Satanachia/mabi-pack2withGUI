#ifndef UIEXTRACT_H
#define UIEXTRACT_H

#include <QWidget>
#include "MabiGlobal.h"

namespace Ui {
class UIExtract;
}

class UIExtract : public QWidget
{
    Q_OBJECT

public:
    explicit UIExtract(QWidget *parent = nullptr);
    ~UIExtract();

private slots:
    void on_fromBtn_clicked();

    void on_toBtn_clicked();

    void on_execBtn_clicked();

    void on_cancBtn_clicked();

private:
    Ui::UIExtract *ui;
    EXTRACT m_extract;
};

#endif // UIEXTRACT_H
