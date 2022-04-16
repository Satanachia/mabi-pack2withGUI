#include "MabiGlobal.h"

QMap<QString, std::shared_ptr<MabiCache>> MabiGlobal::g_fileCache = QMap<QString, std::shared_ptr<MabiCache>>();
QSettings MabiGlobal::g_setting = QSettings("./resource/config.ini", QSettings::IniFormat);

MabiGlobal::MabiGlobal()
{
}
