/********************************************************************************
** Form generated from reading UI file 'newmail.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMAIL_H
#define UI_NEWMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_NewMail
{
public:
    QDialogButtonBox *buttonBox;
    QTextBrowser *textBrowser;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *NewMail)
    {
        if (NewMail->objectName().isEmpty())
            NewMail->setObjectName(QStringLiteral("NewMail"));
        NewMail->resize(400, 300);
        buttonBox = new QDialogButtonBox(NewMail);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(210, 240, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textBrowser = new QTextBrowser(NewMail);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 40, 361, 191));
        comboBox = new QComboBox(NewMail);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 10, 131, 22));
        label = new QLabel(NewMail);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 101, 16));
        pushButton = new QPushButton(NewMail);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 10, 75, 23));

        retranslateUi(NewMail);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewMail, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewMail, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewMail);
    } // setupUi

    void retranslateUi(QDialog *NewMail)
    {
        NewMail->setWindowTitle(QApplication::translate("NewMail", "Dialog", 0));
        label->setText(QApplication::translate("NewMail", "Select the reciever:", 0));
        pushButton->setText(QApplication::translate("NewMail", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class NewMail: public Ui_NewMail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMAIL_H
