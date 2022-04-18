#ifndef MABIMODMANAGER_H
#define MABIMODMANAGER_H
#include "MabiGlobal.h"


class MabiModManager
{
public:
    MabiModManager();
    MabiErrorStatus getMabiMods(QMap<QString, int>& mods);
    MabiErrorStatus updateAllMods();
    MabiErrorStatus insertByIt(QString& itPath);
    MabiErrorStatus insertByTxt(QString& txtPath);
    MabiErrorStatus remove();
    MabiErrorStatus removePermanently();
    MabiErrorStatus removeIt();
    bool needToUpdate();
};

#endif // MABIMODMANAGER_H
