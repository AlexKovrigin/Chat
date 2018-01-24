/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(243, 289);
        label = new QLabel(About);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 221, 211));
        pushButton = new QPushButton(About);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 260, 75, 23));
        label_2 = new QLabel(About);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 210, 41, 41));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/plane.ico")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(About);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 200, 111, 16));
        label_4 = new QLabel(About);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 220, 171, 41));

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "Dialog", 0));
        label->setText(QApplication::translate("About", "<html><head/><body><p align=\"center\">\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \321\201\320\276\320\267\320\264\320\260\320\275\320\260 \321\202\320\260\320\272-\321\201\320\265\320\261\320\265 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\201\321\202\320\276\320\274</p><p align=\"center\">\320\250\321\203\321\200\320\270\320\272\320\276\320\274 \320\232\320\276\320\262\321\200\320\270\320\266\320\272\320\270\320\275\321\213\320\274</p><p align=\"center\">\320\220 \321\202\320\260\320\272\320\266\320\265 \320\276\320\277\321\213\321\202\320\275\321\213\320\274 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\201\321\202\320\276\320\274</p><p align=\"center\">\320\232\320\276\320\275\320\264\321\200\320\260\321\210\320\276\320\262\321\213\320\274 \320\241\320\265\321\200\320\263\320\265\320\265\320\274 \320\241\320\265\321\200\320\263\320\265\320\265\320\262\320\270\321\207\320\265\320\274</p><p align=\"center\">\320\230"
                        "\320\267\320\264\320\260\321\202\320\265\320\273\321\214: \320\227\320\220\320\236 &quot;\320\222 \320\223\320\276\321\201\321\202\321\217\321\205 \320\243 \320\250\321\203\321\200\320\270\320\272\320\260&quot;</p><p align=\"center\"><br/>v. 2. 1</p></body></html>", 0));
        pushButton->setText(QApplication::translate("About", "Close", 0));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("About", "Made by Alex Kovrigin", 0));
        label_4->setText(QApplication::translate("About", "<html><head/><body><p>Copyright 2017 Qt Alex Projects.</p><p>All rights reserved.</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
