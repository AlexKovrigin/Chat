#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QByteArray>
#include <QHash>
#include <QTime>
#include <QMessageBox>
#include <QVector>
namespace Ui {
class chatServer;
}

class chatServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit chatServer(QWidget *parent = 0);
    ~chatServer();
private slots:
    void newConnection();
    void on_actionClear_triggered();

private:
    Ui::chatServer *ui;
    QTcpServer* server;
    void displMessage(QString message);
    QString checkMessage(QString ip);
    QVector<QString> ipList;
    QVector<QString> messageList;
    QVector<QString> senderList;
    QVector<QString> allNames;
    QVector<QString> allIp;
    QString getname(QString message);
    QUdpSocket udpSocket;
};

#endif // CHATSERVER_H
