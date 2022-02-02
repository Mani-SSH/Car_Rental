/********************************************************************************
** Form generated from reading UI file 'loginadmin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINADMIN_H
#define UI_LOGINADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginAdmin
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_Login;
    QLabel *label;
    QLineEdit *lineEdit_username;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginAdmin)
    {
        if (LoginAdmin->objectName().isEmpty())
            LoginAdmin->setObjectName(QString::fromUtf8("LoginAdmin"));
        LoginAdmin->resize(600, 700);
        centralwidget = new QWidget(LoginAdmin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_Login = new QGroupBox(centralwidget);
        groupBox_Login->setObjectName(QString::fromUtf8("groupBox_Login"));
        groupBox_Login->setGeometry(QRect(120, 170, 351, 381));
        label = new QLabel(groupBox_Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 101, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        lineEdit_username = new QLineEdit(groupBox_Login);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(20, 90, 301, 28));
        QFont font1;
        font1.setPointSize(10);
        lineEdit_username->setFont(font1);
        label_2 = new QLabel(groupBox_Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 160, 101, 20));
        label_2->setFont(font);
        lineEdit_password = new QLineEdit(groupBox_Login);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(20, 190, 301, 28));
        lineEdit_password->setFont(font1);
        lineEdit_password->setEchoMode(QLineEdit::Password);
        LoginAdmin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginAdmin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 25));
        LoginAdmin->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginAdmin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginAdmin->setStatusBar(statusbar);

        retranslateUi(LoginAdmin);

        QMetaObject::connectSlotsByName(LoginAdmin);
    } // setupUi

    void retranslateUi(QMainWindow *LoginAdmin)
    {
        LoginAdmin->setWindowTitle(QCoreApplication::translate("LoginAdmin", "LoginAdmin", nullptr));
        groupBox_Login->setTitle(QCoreApplication::translate("LoginAdmin", "Log In", nullptr));
        label->setText(QCoreApplication::translate("LoginAdmin", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("LoginAdmin", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginAdmin: public Ui_LoginAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINADMIN_H
