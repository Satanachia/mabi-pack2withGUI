#include "MabiFileTreeView.h"

MabiErrorStatus MabiFileTreeView::getFileTreeView(QStandardItemModel &model, const QString &filePath)
{
    //extern QMap<QString, std::shared_ptr<MabiCache>> g_fileCache;
    if (model.rowCount() == 0)
    {
        QStandardItem* data = new QStandardItem("data");
        model.appendRow(data);
        m_root_item = data;
    }
    else{
        m_root_item = model.item(0);
    }

    // 获取 list 结果
    const char* res = m_list(filePath.toUtf8().data());
    // 将结果转换为 QString, 此时的格式为 "data/xxx/xxx.xml,data/yyy/yyy.txt..."
    QString fileInfo(res);
    // 生成文件 list
    auto files = fileInfo.split(",");
    // 去除最后一个空数据
    files.pop_back();
    for (auto& item : files){
        if (item.length() == 0) continue;
        // 将文件按路径分段成字符串 list
        QStringList splits;
        if (fileInfo.contains("/"))
        {
            splits = item.split("/");
        }
        else
        {
            splits = item.split("\\");
        }

        for (int i = 1; i < splits.length(); ++i){
            // 子目录
            if (i < splits.length() - 1){
                auto nums = m_root_item->rowCount();
                bool flag = false;
                for (int j = 0; j < nums; ++j){
                    if (m_root_item->child(j)->text() == splits[i]){
                        m_root_item = m_root_item->child(j);
                        flag = true;
                        break;
                    }
                }
                // 相应的子目录不存在->创建子目录
                if (!flag){
                    QStandardItem* root_item = new QStandardItem(splits[i]);
                    m_root_item->appendRow(root_item);
                    m_root_item = root_item;
                }
            }
            // 文件->添加到相应的子目录中
            else{
                QStandardItem* root_item = new QStandardItem(splits[i]);
                MabiCache tmp;
                tmp.setDocPath(filePath);
                tmp.setFilePath(item);
                if (!MabiGlobal::g_fileCache.contains(item))
                    MabiGlobal::g_fileCache.insert(item, std::make_shared<MabiCache>(tmp));
                m_root_item->appendRow(root_item);
                m_root_item = model.item(0);
            }
        }
    }
#ifndef QT_DEBUG
    delete [] res;
#endif
    return MabiErrorStatus::eOk;
}

MabiErrorStatus MabiFileTreeView::getDirTreeView(QStandardItemModel &model, const QString &dirInfo)
{
    // 解析路径
    QDir pathDir(dirInfo);
    // 设置过滤器->it文件
    QStringList filters;
    filters << QString("*.it");
    pathDir.setFilter(QDir::Files); //设置类型过滤器
    pathDir.setNameFilters(filters);
    QFileInfoList list = pathDir.entryInfoList();
    for (auto& file : list){
        getFileTreeView(model, file.absoluteFilePath());
    }
    return MabiErrorStatus::eOk;
}

MabiFileTreeView::MabiFileTreeView()
{
    dll_Import_Mgr mgr;
    mgr.loadListFun(m_list);
}

MabiFileTreeView::~MabiFileTreeView()
{
//    delete m_root_item;
//    m_root_item = nullptr;
}

TreeViewHelper::TreeViewHelper()
{

}

void TreeViewHelper::run()
{

}
