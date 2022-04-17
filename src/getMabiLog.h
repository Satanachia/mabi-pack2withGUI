#ifndef GETMABILOG_H
#define GETMABILOG_H

#include <Windows.h>
#include <iostream>
#include <shlobj.h>
#include <QString>
#include <string>
#include <sys/stat.h>
#include <QFile>
#include <QDebug>
#include "MabiGlobal.h"

#pragma comment(lib, "shell32.lib")

// 读取游戏的log文件->获取游戏位置，补丁版本号
class mabiLog
{
public:
    mabiLog(MabiErrorStatus& es);
    ~mabiLog();
    const QString& patch_version() const;
    const QString& game_path() const;
private:
    QString m_patch_version = "";
    QString m_game_dir = "";
};

inline mabiLog::mabiLog(MabiErrorStatus& es)
{
    // 获取当前用户的文档地址
    WCHAR my_documents[MAX_PATH];
    HRESULT result = SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, my_documents);
    if (result != S_OK)
    {
        es = MabiErrorStatus::eNotFound;
        return;
    }
    // 拼接文档地址与洛奇log地址
    std::wstring path = my_documents;
    path += L"\\洛奇\\错误报告\\launcher_log.txt";
    struct _stat64 buffer;
    if (_wstat64(path.c_str(), &buffer) == 0){
        QFile log(QString::fromStdWString(path));
        // 读log文件
        if (log.open(QIODevice::ReadOnly))
        {
            MabiGlobal::g_setting.setValue("log_path", QString::fromStdWString(path));
            QTextStream stream(&log);
            while(m_game_dir == "" || m_patch_version == "")
            {
                QString str = stream.readLine();
                if (str.contains("Game directory"))
                {
                    m_game_dir = str.remove("Game directory is ").remove("\"").remove(".");
                }
                if (str.contains("patch version"))
                {
                    m_patch_version = str.remove("patch version : ");
                }
                if (stream.atEnd()){
                    break;
                }
            }
            log.close();
            es = MabiErrorStatus::eOk;
            return;
        }
        else{
            es = MabiErrorStatus::eNotFound;
            return;
        }
    }
    else{
        es = MabiErrorStatus::eNotFound;
        return;
    }
}

inline mabiLog::~mabiLog()
{
}

inline const QString &mabiLog::patch_version() const
{
    return m_patch_version;
}

inline const QString &mabiLog::game_path() const
{
    return m_game_dir;
}

#endif // GETMABILOG_H
