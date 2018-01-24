#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>
#include <QMessageBox>
#include <QVector>
#include <QDateTime>
#include <about.h>
#include <login.h>


namespace Ui {
class ChatClient;
}

class ChatClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatClient(QWidget *parent = 0);
    ~ChatClient();
    QString ipSendto = "";
    QString myname = "";

private slots:
    void on_sendBtn_clicked();

    void on_actionAbout_us_triggered();

    void on_ckeckBtn_clicked();

    void on_incomingList_clicked(const QModelIndex &index);

    void on_incomingList_activated(const QModelIndex &index);

    void on_namesBtn_clicked();


    void on_comboBox_activated(const QString &arg1);

    void on_newlook_clicked();

private:
    Ui::ChatClient *ui;
    QTcpSocket* socket = new QTcpSocket(this);
    QVector<QString> mesArray;
    QVector<QString> sendersArray;
    bool viewMode = false;
    int loginChat();

};

#endif // CHATCLIENT_H
