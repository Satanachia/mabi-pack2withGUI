#include "MabiModManager.h"

MabiModManager::MabiModManager()
{

}

MabiErrorStatus MabiModManager::getMabiMods(QStringList &mods)
{
    return MabiErrorStatus::eOk;
}

MabiErrorStatus MabiModManager::updateAllMods()
{
    return MabiErrorStatus::eOk;
}

MabiErrorStatus MabiModManager::insertByIt(QString &itPath)
{
    return MabiErrorStatus::eOk;
}

MabiErrorStatus MabiModManager::insertByTxt(QString &txtPath)
{
    return MabiErrorStatus::eOk;
}

MabiErrorStatus MabiModManager::remove()
{
    return MabiErrorStatus::eOk;
}

MabiErrorStatus MabiModManager::removePermanently()
{
    return MabiErrorStatus::eOk;
}

MabiErrorStatus MabiModManager::removeIt()
{
    return MabiErrorStatus::eOk;
}

bool MabiModManager::needToUpdate()
{
    return true;
}
