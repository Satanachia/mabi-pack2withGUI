#include "MabiCache.h"

MabiCache::MabiCache()
{
    m_documentPath = "";
    m_filePath = "";
    m_content = "";
}

void MabiCache::setDocPath(const QString &path)
{
    m_documentPath = path;
}

void MabiCache::setFilePath(const QString &path)
{
    m_filePath = path;
}

void MabiCache::setContent(const QString &content)
{
    m_content = content;
}

QString MabiCache::getDocPath()
{
    return m_documentPath;
}

QString MabiCache::getFilePath()
{
    return m_filePath;
}

QString MabiCache::getContent()
{
    return m_content;
}
