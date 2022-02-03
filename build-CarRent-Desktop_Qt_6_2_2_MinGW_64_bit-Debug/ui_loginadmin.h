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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginAdmin
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_Login;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QCheckBox *checkBox_showPassword;
    QLabel *label_hintUsername;
    QLabel *label_hintPassword;
    QPushButton *pushButton_login;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginAdmin)
    {
        if (LoginAdmin->objectName().isEmpty())
            LoginAdmin->setObjectName(QString::fromUtf8("LoginAdmin"));
        LoginAdmin->resize(600, 700);
        QFont font;
        font.setFamilies({QString::fromUtf8("Gotham")});
        LoginAdmin->setFont(font);
        centralwidget = new QWidget(LoginAdmin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_Login = new QGroupBox(centralwidget);
        groupBox_Login->setObjectName(QString::fromUtf8("groupBox_Login"));
        groupBox_Login->setGeometry(QRect(120, 100, 351, 451));
        lineEdit_username = new QLineEdit(groupBox_Login);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(20, 140, 311, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Gotham")});
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        lineEdit_username->setFont(font1);
        lineEdit_username->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit_password = new QLineEdit(groupBox_Login);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(20, 230, 311, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Gotham")});
        font2.setPointSize(10);
        font2.setBold(true);
        lineEdit_password->setFont(font2);
        lineEdit_password->setEchoMode(QLineEdit::Password);
        checkBox_showPassword = new QCheckBox(groupBox_Login);
        checkBox_showPassword->setObjectName(QString::fromUtf8("checkBox_showPassword"));
        checkBox_showPassword->setGeometry(QRect(30, 280, 131, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Gotham")});
        font3.setPointSize(8);
        checkBox_showPassword->setFont(font3);
        label_hintUsername = new QLabel(groupBox_Login);
        label_hintUsername->setObjectName(QString::fromUtf8("label_hintUsername"));
        label_hintUsername->setGeometry(QRect(20, 190, 151, 20));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Gotham")});
        font4.setPointSize(7);
        label_hintUsername->setFont(font4);
        label_hintPassword = new QLabel(groupBox_Login);
        label_hintPassword->setObjectName(QString::fromUtf8("label_hintPassword"));
        label_hintPassword->setGeometry(QRect(20, 300, 151, 20));
        label_hintPassword->setFont(font4);
        pushButton_login = new QPushButton(groupBox_Login);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(30, 370, 291, 41));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(227, 227, 227, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(160, 160, 160, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush5(QColor(240, 240, 240, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(105, 105, 105, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        QBrush brush7(QColor(0, 120, 215, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        QBrush brush8(QColor(0, 0, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush8);
        QBrush brush9(QColor(255, 0, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush9);
        QBrush brush10(QColor(245, 245, 245, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        QBrush brush11(QColor(0, 0, 0, 255));
        brush11.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush11);
        QBrush brush12(QColor(255, 255, 220, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush12);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush13(QColor(0, 0, 0, 128));
        brush13.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        QBrush brush14(QColor(0, 0, 0, 255));
        brush14.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush14);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        QBrush brush15(QColor(120, 120, 120, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        QBrush brush16(QColor(247, 247, 247, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush16);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush15);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        QBrush brush17(QColor(0, 0, 0, 255));
        brush17.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush17);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush12);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush13);
#endif
        pushButton_login->setPalette(palette);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Gotham")});
        font5.setPointSize(11);
        font5.setBold(true);
        pushButton_login->setFont(font5);
        label = new QLabel(groupBox_Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 331, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Gotham")});
        font6.setPointSize(16);
        label->setFont(font6);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);
        LoginAdmin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginAdmin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 22));
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
        groupBox_Login->setTitle(QString());
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("LoginAdmin", "Username", nullptr));
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("LoginAdmin", "Password", nullptr));
        checkBox_showPassword->setText(QCoreApplication::translate("LoginAdmin", "Show Password", nullptr));
        label_hintUsername->setText(QCoreApplication::translate("LoginAdmin", "Hint", nullptr));
        label_hintPassword->setText(QCoreApplication::translate("LoginAdmin", "Hint", nullptr));
        pushButton_login->setText(QCoreApplication::translate("LoginAdmin", "LOGIN", nullptr));
        label->setText(QCoreApplication::translate("LoginAdmin", "ADMIN LOGIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginAdmin: public Ui_LoginAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINADMIN_H
