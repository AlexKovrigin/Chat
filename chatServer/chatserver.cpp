#include "chatserver.h"
#include "ui_chatserver.h"

chatServer::chatServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chatServer)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()),this, SLOT(newConnection()));
    QMessageBox d;
    if(!server->listen(QHostAddress::Any, 5001)) // запускаем сервер
    {
        d.setText("Error! Server can't start!");
    }
    else
    {
        d.setText("Server is  up & running");
    }
    d.exec();
}

chatServer::~chatServer()
{
    delete ui;
    server->close();
}

void chatServer::newConnection()
{
    QTcpSocket* socket = server->nextPendingConnection(); // получаем подключение
    if (socket->waitForReadyRead(3000))
    {
        QString s = QString(socket->readAll()); // записываем данные
        QString message = "";
        if(s.left(5) == "check")
            message = checkMessage(getname(s));
        else if(s == "gname")
        {
            for(int i = 0; i< allNames.size(); i++)
                message += allNames.at(i) + "|";
        }
        else if(s.left(4) == "|reg")
        {
            QString regname = s.mid(4);
            if(!allNames.contains(regname)){
                message = "+";
                allNames.push_back(regname);
                allIp.push_back(socket->peerAddress().toString());
            }
            else
            {
                if(socket->peerAddress().toString() == allIp.at(allNames.indexOf(regname)))
                    message = "+";
                else
                    message = "-";
            }

        }
        QDateTime j = QDateTime::currentDateTime();
        QString time = j.toString("HH:mm:ss");
        QString display = "[" + time + "] - " + socket->localAddress().toString() + ": " + s;
        //наводмим красоту
        displMessage(display);
        //вывод
        if(message != "")
        {

            QByteArray dataForWrite;
            dataForWrite = message.toUtf8();
            socket->write(dataForWrite);
            socket->flush();
        }
        else
        {
            int i2 = 0;
            int i4 = 0;
            QString messagetoSave = "";
            QString rectoSave = "";
            QString sender = "";
            for(int i = 0; true; i++)
            {
                if(s[i] == '|')
                {
                    i2 = i + 1;
                    for(int _i = 0; _i < i; _i++)
                        messagetoSave += s[_i];
                    break;
                }
            }
            for(int i3 = i2; true; i3++)
            {
                if(s[i3] == '|')
                {
                    i4 = i3 + 1;
                    for(int _i2 = i2; _i2 < i3; _i2++)
                        rectoSave += s[_i2];
                    break;
                }
            }
            for(int i5 = i4; true; i5++)
            {
                if(s[i5] == '|')
                {
                    for(int _i3 = i4; _i3 < i5; _i3++)
                        sender += s[_i3];
                    break;
                }
            }
            messageList.push_back(messagetoSave);
            ipList.push_back(rectoSave);
            senderList.push_back(sender);
        }
        //socket->write(dataInput);
        //socket->waitForBytesWritten(3000);
        //socket->flush();
    }
    else
    {
        displMessage("No reading materials :(");
        //нечего получать
    }

    socket->close();
}
QString chatServer::getname(QString message)
{
    message = message.mid(6, message.size() - 6);
    return message;
}

QString chatServer::checkMessage(QString ip)
{
    if(ip == "::1")
        ip = "localhost";
    for(int i = 0; i < ipList.size(); i++)
    {
        if(ip.contains(ipList.at(i)))
        {
            QString message = messageList.at(i) + "|" + senderList.at(i) + "|";
            messageList.removeAt(i);
            ipList.removeAt(i);
            senderList.removeAt(i);
            return message;
        }
    }
    return "-";
}

void chatServer::displMessage(QString message)
{
    //функция вывода информации на экран
    QString curText = ui->logBox->toPlainText();
    QString newText = curText + "\n" + message;
    ui->logBox->setText(newText);
}

void chatServer::on_actionClear_triggered()
{
    ui->logBox->clear();
    //очистка
}
