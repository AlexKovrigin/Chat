#include "chatclient.h"
#include "ui_chatclient.h"

ChatClient::ChatClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatClient)
{
    fail:
    int res = loginChat();
    if(res == 0)
        goto fail;
    else if(res == 2){
        this->close();
    }
    else {
        ui->setupUi(this);
        on_newlook_clicked();
    }
}

ChatClient::~ChatClient()
{
    delete ui;
}
void ChatClient::on_sendBtn_clicked()
{
    QMessageBox t; // инфо окно
    QString message = ui->messageBrowser->toPlainText(); // сообщение
    QString reciever = ui->comboBox->currentText();
    if(ipSendto.isEmpty() || message.contains('|') || message.isEmpty() || reciever.isEmpty() || myname.isEmpty() || reciever.contains('|'))
    {
        t.setText("Some of your imputs is incorrect!");
        t.exec();
        return;
    }
    QString dataForWrite = message + "|" + reciever + "|" + myname + "|";
    socket->connectToHost(ipSendto, 5001); // подключение
    if(socket->waitForConnected(3000))
    {

        QByteArray data = dataForWrite.toUtf8(); // без коментариев
        socket->write(data); // пишем
        socket->flush();// отправляем
        t.setText("Message has been delievered!");
        t.exec(); // отчет о выполненной работе
    }
    else
    {
        t.setText("We couldn't connect to " + ipSendto + " :(");
        t.exec(); // в случае неудачи
    }
    socket->close();
}
int ChatClient::loginChat()
{
    Login a;
    a.exec();
    if(!a.success)
        return 2;

    QMessageBox er;
    ipSendto = a.serverip;
    myname = a.name;
    if(myname.isEmpty())
    {
        er.setText("Your name is empty :(");
        er.exec();
        return 0;
    }
    socket->connectToHost(ipSendto, 5001); // подключение
    if(socket->waitForConnected(3000))
    {
        QString check = "|reg" + myname;
        QByteArray data = check.toUtf8(); // без коментариев
        socket->write(data); // пишем
        socket->flush();// отправляем
        if(socket->waitForReadyRead(5000))
        {
            QString s = QString(socket->readAll());
            if(s == "-" || myname.isEmpty())
            {
                er.setText("Your name was taken or is incorrect :(");
                er.exec();
                socket->close();
                return 0;
            }
            else
            {
                er.setText("Succefully logged in! :)");
                er.exec();
                socket->close();
                return 1;
            }

        }
    }
    else
    {
        er.setText("We couldn't connect to server at " + ipSendto +" :(");
        er.exec();
        socket->close();
        return 0;
    }

    return 0;
}

void ChatClient::on_actionAbout_us_triggered()
{
    About g;
    g.exec();
}


void ChatClient::on_ckeckBtn_clicked()
{
    QMessageBox a;
    socket->connectToHost(ipSendto, 5001); // подключение
    if(socket->waitForConnected(3000))
    {
        QString check = "check|" + myname;
        QByteArray data = check.toUtf8(); // без коментариев
        socket->write(data); // пишем
        socket->flush();// отправляем
        if(socket->waitForReadyRead(5000))
        {
            QString s = QString(socket->readAll());
            if(s == "-")
                return;
            int i2 = 0;
            QString messagetoSave = "";
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
                    for(int _i2 = i2; _i2 < i3; _i2++)
                        sender += s[_i2];
                    break;
                }
            }
            mesArray.push_front(messagetoSave);
            sendersArray.push_front(sender);
            QDateTime j = QDateTime::currentDateTime();
            QString time = j.toString("HH:mm:ss");
            QString display = "[" + time + "] - " + messagetoSave +  " from " + sender;
            ui->incomingList->insertItem(0, display);
        }
    }
    else
    {
        a.setText("We couldn't connect to " + ipSendto + " :(");

    }
    a.exec(); // в случае неудачи
    socket->close();
}

void ChatClient::on_incomingList_clicked(const QModelIndex &index)
{

    on_incomingList_activated(index);
}

void ChatClient::on_incomingList_activated(const QModelIndex &index)
{
    int col = index.row();
    ui->messageBrowser->setText(mesArray.at(col));
    ui->senderLine->setText(sendersArray.at(col));
}

void ChatClient::on_namesBtn_clicked()
{
    QMessageBox a;
    socket->connectToHost(ipSendto, 5001); // подключение
    if(socket->waitForConnected(3000))
    {
        QString check = "gname";
        QByteArray data = check.toUtf8(); // без коментариев
        socket->write(data); // пишем
        socket->flush();// отправляем
        if(socket->waitForReadyRead(5000))
        {

            QString s = QString(socket->readAll());
            ui->comboBox->clear();
            QString temp;
            int prevInt = 0;
            for(int i = 0; i < s.size(); i++)
            {
                if(s.at(i) == '|')
                {
                    for(int i2 = prevInt; i2 < i; i2++)
                        temp += s[i2];
                    prevInt = i + 1;
                    ui->comboBox->addItem(temp);
                    temp = "";
                }
            }
        }
    }
    else
    {
        a.setText("We couldn't connect to " + ipSendto + " :(");
        a.exec();
    }
    socket->close();
}


void ChatClient::on_comboBox_activated(const QString &arg1)
{
    //on_namesBtn_clicked();
}

void ChatClient::on_newlook_clicked()
{

    viewMode = !viewMode;
    ui->incomingList->setEnabled(viewMode);
    ui->messageBrowser->setReadOnly(viewMode);
    ui->senderLine->setEnabled(viewMode);
    ui->sendBtn->setEnabled(!viewMode);
    ui->comboBox->setEnabled(!viewMode);
    if(viewMode)
    {
        ui->newlook->setText("View Mode");
        ui->messageBrowser->clear();
        if(ui->incomingList->count() != 0)
            ui->incomingList->itemActivated(ui->incomingList->item(0));
    }
    else
    {
        ui->newlook->setText("Writing mode");
        ui->messageBrowser->setText("");
    }
}

