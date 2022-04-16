#ifndef UISETTINGS_H
#define UISETTINGS_H

#include <QWidget>
#include "MabiGlobal.h"
#include <QFileDialog>

namespace Ui {
class UISettings;
}

class UISettings : public QWidget
{
    Q_OBJECT

public:
    explicit UISettings(QWidget *parent = nullptr);
    ~UISettings();

private slots:
    void on_gamePath_clicked();

    void on_packPath_clicked();

    void on_logPath_clicked();

    void on_okBtn_clicked();

private:
    Ui::UISettings *ui;
};

#endif // UISETTINGS_H
