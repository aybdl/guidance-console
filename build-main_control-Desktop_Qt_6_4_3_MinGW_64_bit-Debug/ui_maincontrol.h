/********************************************************************************
** Form generated from reading UI file 'maincontrol.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCONTROL_H
#define UI_MAINCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainControl
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainControl)
    {
        if (MainControl->objectName().isEmpty())
            MainControl->setObjectName("MainControl");
        MainControl->resize(800, 600);
        centralwidget = new QWidget(MainControl);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 20, 181, 271));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(100, 30, 41, 21));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 61, 16));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 110, 141, 101));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 40, 20));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(230, 20, 231, 271));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 61, 16));
        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 50, 101, 21));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 90, 80, 18));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(120, 90, 80, 18));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 160, 80, 18));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 120, 80, 18));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(120, 120, 80, 18));
        MainControl->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainControl);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainControl->setMenuBar(menubar);
        statusbar = new QStatusBar(MainControl);
        statusbar->setObjectName("statusbar");
        MainControl->setStatusBar(statusbar);

        retranslateUi(MainControl);

        QMetaObject::connectSlotsByName(MainControl);
    } // setupUi

    void retranslateUi(QMainWindow *MainControl)
    {
        MainControl->setWindowTitle(QCoreApplication::translate("MainControl", "MainControl", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainControl", "\346\225\260\346\215\256\345\217\221\351\200\201", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainControl", "30010", nullptr));
        label->setText(QCoreApplication::translate("MainControl", "udp\345\217\221\351\200\201\347\253\257\345\217\243", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainControl", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">16.34\357\274\232\350\275\257\344\273\266\350\277\236\346\216\245\346\210\220\345\212\237</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">16.34\357\274\232\346\225\260\346\215\256\344\274\240\350\276\223\345\274\200\345\247\213</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:"
                        "0px; -qt-block-indent:0; text-indent:0px;\">16.40\357\274\232\346\225\260\346\215\256\344\274\240\350\276\223\347\273\223\346\235\237</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainControl", "\347\212\266\346\200\201\346\230\276\347\244\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainControl", "\344\273\277\347\234\237\346\216\247\345\210\266", nullptr));
        label_3->setText(QCoreApplication::translate("MainControl", "\344\275\234\344\270\232\346\226\207\344\273\266\351\200\211\346\213\251", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainControl", "\345\215\217\345\220\214\346\216\242\346\265\2133.txt", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainControl", "\347\232\204", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainControl", "\346\226\260\345\273\272\351\241\271\347\233\256\345\257\274\345\274\271", nullptr));

        pushButton->setText(QCoreApplication::translate("MainControl", "\350\275\257\344\273\266\350\277\236\346\216\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainControl", "\345\274\200\345\247\213\344\273\277\347\234\237", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainControl", "\346\225\260\346\215\256\344\277\235\345\255\230", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainControl", "\346\232\202\345\201\234/\347\273\247\347\273\255", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainControl", "\347\273\223\346\235\237\344\273\277\347\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainControl: public Ui_MainControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCONTROL_H
