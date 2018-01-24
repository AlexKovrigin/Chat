#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    success = false;
    //UdpChat();
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_accepted()
{
    name = ui->nameLine->text();
    serverip = ui->serverIp->text();
    success = true;
    close();
}

void Login::on_buttonBox_rejected()
{
    success = false;
    close();
}
/*void Login::UdpChat(int port = 5002) {
  socket = new QUdpSocket(this);
  socket->bind(QHostAddress::Any, port);
  connect(socket, SIGNAL(readyRead()), this, SLOT(read()));
  QString message = "hi";
  QByteArray data = message.toUtf8();
  socket->writeDatagram(data, QHostAddress::Broadcast, port);
  // тут еще какой то код конструктора //
}
*/
