#include "readfromweburl.h"

readFromWeburl::readFromWeburl()
{
    m_manager = new QNetworkAccessManager(this);    //新建QNetworkAccessManager对象
    connect(m_manager,SIGNAL(finished(QNetworkReply*)), this,
            SLOT(slot_replayFinished(QNetworkReply*))); //关联信号和槽

    QUrl url("http://vert.luoqi.com.cn/patch_live1.txt");
    m_manager->get(QNetworkRequest(url));//发送请求
}

readFromWeburl::~readFromWeburl()
{

}

void readFromWeburl::slot_replayFinished(QNetworkReply *reply){
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    //使用utf8编码, 这样可以显示中文
    QString str = codec->toUnicode(reply->readAll());
    //ui->textBrowser->width(800);
    reply->deleteLater();//最后要释放replay对象
}
