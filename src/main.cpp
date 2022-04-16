#include "UIMainWindow.h"
#include "UIExplorer.h"

#include <QApplication>
#include <QSettings>
#include <QAction>
#include <QPushButton>
#include "MabiGlobal.h"
#include "getMabiLog.h"
#include <QTextCodec>
#include "UISettings.h"

void mabipackInit();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UIMainWindow w;
    w.show();
    mabipackInit();
    return a.exec();
}

void mabipackInit()
{
    // 获取 setting， log
    if (MabiGlobal::g_setting.value("file_path").toString() == "") MabiGlobal::g_setting.setValue("file_path", "./");
    if (MabiGlobal::g_setting.value("file_dir").toString() == "") MabiGlobal::g_setting.setValue("file_dir", "./");
    MabiErrorStatus es;
    mabiLog myLog(es);
    // 如果 log 文件获取正常，并且 setting 中未有游戏信息，设置游戏路径与版本号
    if (es == MabiErrorStatus::eOk && MabiGlobal::g_setting.value("game_path").toString() == "" && MabiGlobal::g_setting.value("patch_version").toString() == ""){
        MabiGlobal::g_setting.setValue("game_path", myLog.game_path());
        MabiGlobal::g_setting.setValue("package_path", myLog.game_path() + "package");
        MabiGlobal::g_setting.setValue("patch_version", myLog.patch_version());
    }
    if (MabiGlobal::g_setting.value("game_path").toString() == "" || MabiGlobal::g_setting.value("patch_version").toString() == ""){
        // 如 log 文件找不到，对话框提示用户选择游戏文件夹
        UISettings* uiSet = new UISettings();
        uiSet->setAttribute(Qt::WA_DeleteOnClose);
        uiSet->show();
    }
    // 版本号比对
    if (MabiGlobal::g_setting.value("patch_version").toString() != MabiGlobal::g_setting.value("mod_version").toString())
    {
        // 可能存在更新，对话框提示
        QMessageBox::information(nullptr, "提醒", "可能需要更新Mod补丁，如您第一次打开本软件请忽视此信息.", QMessageBox::Ok);
        MabiGlobal::g_setting.setValue("mod_version", MabiGlobal::g_setting.value("patch_version").toString());
        /*to do...
         * call manager()
        */
    }
    return;
}
