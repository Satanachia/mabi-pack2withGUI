#ifndef MABIFILETREEVIEW_H
#define MABIFILETREEVIEW_H

#include <QStandardItemModel>
#include "MabiGlobal.h"
#include <QDir>
#include "dll_import_mgr.h"
#include <QThread>

class TreeViewHelper : public QThread
{
public:
    TreeViewHelper();
protected:
    void run();
    void subGetFileTreeView(QStandardItemModel&, const QString& fileInfo, const LIST&);
signals:
    void isDone();
};

class MabiFileTreeView
{
public:
    MabiErrorStatus getFileTreeView(QStandardItemModel&, const QString& fileInfo);
    MabiErrorStatus getDirTreeView(QStandardItemModel&, const QString& dirInfo);
    MabiFileTreeView();
    ~MabiFileTreeView();
    //qRegisterMetaType<QStandardItemModel>(QStandardItemModel);
    //connect(THIS, SIGNAL(infoTrans(QStandardItemModel&, const QString& fileInfo, const LIST&)), &m_thread, SLOT(subGetFileTreeView(QStandardItemModel&, const QString& fileInfo, const LIST&)));

signals:
    void infoTrans(QStandardItemModel&, const QString& fileInfo, const LIST&);

private:
    QStandardItem* m_root_item;
    LIST m_list;
    //TreeViewHelper m_thread;
};

#endif // MABIFILETREEVIEW_H
