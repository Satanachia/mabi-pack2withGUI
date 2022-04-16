#ifndef MABIGLOBAL_H
#define MABIGLOBAL_H

#include "MabiCache.h"
#include <QList>
#include <QMap>
#include <QSettings>
#include "dll_import_mgr.h"
#include <QDesktopServices>

class MabiErrorStatus
{
public:
    enum Enum
    {
        eOk = 0,
        eNullPtr,
        eNotFound,
        eNotApplicable,
        eComputeError,
        eInvalidInput,
    };
    MabiErrorStatus() {m_value = MabiErrorStatus::eOk;}
    MabiErrorStatus(Enum value) {m_value = value;}
    operator bool() {return m_value == MabiErrorStatus::eOk;}
    operator MabiErrorStatus::Enum() {return m_value;}
    bool operator==(const MabiErrorStatus& anohter) {return m_value == anohter.m_value;}
    bool operator==(const MabiErrorStatus::Enum es) { return m_value == es;}
    bool operator!=(const MabiErrorStatus& another) {return m_value != another.m_value;}
    bool operator!=(const MabiErrorStatus::Enum es) {return m_value != es;}
private:
    Enum m_value = eOk;

};

class MabiGlobal
{
public:
    MabiGlobal();
    static QMap<QString, std::shared_ptr<MabiCache>> g_fileCache;
    static QSettings g_setting; // = QSettings("./resource/config.ini", QSettings::IniFormat);
};

#endif // MABIGLOBAL_H
