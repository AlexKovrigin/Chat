/********************************************************************************
** Form generated from reading UI file 'chatclient.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATCLIENT_H
#define UI_CHATCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatClient
{
public:
    QAction *actionUpdate_Server_List;
    QAction *actionAbout_us;
    QAction *actionChange_My_Server_Ip;
    QWidget *centralWidget;
    QPushButton *sendBtn;
    QTextBrowser *messageBrowser;
    QPushButton *ckeckBtn;
    QListWidget *incomingList;
    QLineEdit *senderLine;
    QPushButton *namesBtn;
    QComboBox *comboBox;
    QPushButton *newlook;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatClient)
    {
        if (ChatClient->objectName().isEmpty())
            ChatClient->setObjectName(QStringLiteral("ChatClient"));
        ChatClient->resize(479, 372);
        QIcon icon;
        icon.addFile(QStringLiteral(":/plane.ico"), QSize(), QIcon::Normal, QIcon::Off);
        ChatClient->setWindowIcon(icon);
        actionUpdate_Server_List = new QAction(ChatClient);
        actionUpdate_Server_List->setObjectName(QStringLiteral("actionUpdate_Server_List"));
        actionAbout_us = new QAction(ChatClient);
        actionAbout_us->setObjectName(QStringLiteral("actionAbout_us"));
        actionChange_My_Server_Ip = new QAction(ChatClient);
        actionChange_My_Server_Ip->setObjectName(QStringLiteral("actionChange_My_Server_Ip"));
        centralWidget = new QWidget(ChatClient);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sendBtn = new QPushButton(centralWidget);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(420, 40, 51, 23));
        messageBrowser = new QTextBrowser(centralWidget);
        messageBrowser->setObjectName(QStringLiteral("messageBrowser"));
        messageBrowser->setGeometry(QRect(220, 70, 251, 261));
        messageBrowser->setReadOnly(false);
        ckeckBtn = new QPushButton(centralWidget);
        ckeckBtn->setObjectName(QStringLiteral("ckeckBtn"));
        ckeckBtn->setGeometry(QRect(360, 10, 51, 23));
        incomingList = new QListWidget(centralWidget);
        incomingList->setObjectName(QStringLiteral("incomingList"));
        incomingList->setGeometry(QRect(10, 0, 201, 331));
        senderLine = new QLineEdit(centralWidget);
        senderLine->setObjectName(QStringLiteral("senderLine"));
        senderLine->setGeometry(QRect(220, 40, 71, 20));
        senderLine->setReadOnly(true);
        namesBtn = new QPushButton(centralWidget);
        namesBtn->setObjectName(QStringLiteral("namesBtn"));
        namesBtn->setGeometry(QRect(220, 10, 71, 23));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(290, 40, 121, 22));
        newlook = new QPushButton(centralWidget);
        newlook->setObjectName(QStringLiteral("newlook"));
        newlook->setGeometry(QRect(290, 10, 75, 23));
        ChatClient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChatClient);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 479, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        ChatClient->setMenuBar(menuBar);
        statusBar = new QStatusBar(ChatClient);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChatClient->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionAbout_us);

        retranslateUi(ChatClient);

        QMetaObject::connectSlotsByName(ChatClient);
    } // setupUi

    void retranslateUi(QMainWindow *ChatClient)
    {
        ChatClient->setWindowTitle(QApplication::translate("ChatClient", "Alpha Chat", 0));
        actionUpdate_Server_List->setText(QApplication::translate("ChatClient", "Update Server List", 0));
        actionAbout_us->setText(QApplication::translate("ChatClient", "About us", 0));
        actionChange_My_Server_Ip->setText(QApplication::translate("ChatClient", "Log out", 0));
        sendBtn->setText(QApplication::translate("ChatClient", "Send", 0));
        ckeckBtn->setText(QApplication::translate("ChatClient", "Check", 0));
        namesBtn->setText(QApplication::translate("ChatClient", "Names", 0));
        newlook->setText(QApplication::translate("ChatClient", "New Message", 0));
        menuFile->setTitle(QApplication::translate("ChatClient", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatClient: public Ui_ChatClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATCLIENT_H
