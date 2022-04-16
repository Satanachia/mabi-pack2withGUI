#ifndef MABICACHE_H
#define MABICACHE_H

#include <QString>

class MabiCache
{
public:
    MabiCache();
    void setDocPath(const QString& path);
    void setFilePath(const QString& path);
    void setContent(const QString& content);
    QString getDocPath();
    QString getFilePath();
    QString getContent();

private:
    QString m_documentPath;
    QString m_filePath;
    QString m_content;
};

#endif // MABICACHE_H
