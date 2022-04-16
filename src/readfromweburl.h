#ifndef READFROMWEBURL_H
#define READFROMWEBURL_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtWidgets/QWidget>
#include <QTextCodec>
#include <QString>
#include <QUrl>


class readFromWeburl : public QObject
{
    Q_OBJECT

public:
    explicit readFromWeburl();
    ~readFromWeburl();

private Q_SLOTS:
    void slot_replayFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *m_manager;
    QNetworkReply *m_Reply;
};

#endif // READFROMWEBURL_H
