/********************************************************************************
** Form generated from reading UI file 'loginadmin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
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
    QLabel *label_logo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginAdmin)
    {
        if (LoginAdmin->objectName().isEmpty())
            LoginAdmin->setObjectName(QString::fromUtf8("LoginAdmin"));
        LoginAdmin->resize(600, 700);
        QFont font;
        LoginAdmin->setFont(font);
        LoginAdmin->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(LoginAdmin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox_Login = new QGroupBox(centralwidget);
        groupBox_Login->setObjectName(QString::fromUtf8("groupBox_Login"));
        groupBox_Login->setGeometry(QRect(120, 100, 351, 451));
        groupBox_Login->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_username = new QLineEdit(groupBox_Login);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(20, 140, 311, 41));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        lineEdit_username->setFont(font1);
        lineEdit_username->setCursor(QCursor(Qt::IBeamCursor));
        lineEdit_username->setStyleSheet(QString::fromUtf8("background-color: rgb(151, 177, 196);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10;\n"
""));
        lineEdit_password = new QLineEdit(groupBox_Login);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(20, 230, 311, 41));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        lineEdit_password->setFont(font2);
        lineEdit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(151, 177, 196);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10;"));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        checkBox_showPassword = new QCheckBox(groupBox_Login);
        checkBox_showPassword->setObjectName(QString::fromUtf8("checkBox_showPassword"));
        checkBox_showPassword->setGeometry(QRect(30, 280, 131, 21));
        QFont font3;
        font3.setPointSize(8);
        checkBox_showPassword->setFont(font3);
        checkBox_showPassword->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_hintUsername = new QLabel(groupBox_Login);
        label_hintUsername->setObjectName(QString::fromUtf8("label_hintUsername"));
        label_hintUsername->setGeometry(QRect(20, 190, 151, 20));
        QFont font4;
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
        QLinearGradient gradient(0.251, 0.216, 0.811, 0.898);
        gradient.setSpread(QGradient::ReflectSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0.255556, QColor(0, 128, 218, 255));
        QBrush brush1(gradient);
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
        QLinearGradient gradient1(0.251, 0.216, 0.811, 0.898);
        gradient1.setSpread(QGradient::ReflectSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0.255556, QColor(0, 128, 218, 255));
        QBrush brush5(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush5);
        QLinearGradient gradient2(0.251, 0.216, 0.811, 0.898);
        gradient2.setSpread(QGradient::ReflectSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0.255556, QColor(0, 128, 218, 255));
        QBrush brush6(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        QBrush brush7(QColor(105, 105, 105, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        QBrush brush8(QColor(0, 120, 215, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush8);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        QBrush brush9(QColor(0, 0, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush9);
        QBrush brush10(QColor(255, 0, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush10);
        QBrush brush11(QColor(245, 245, 245, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush11);
        QBrush brush12(QColor(0, 0, 0, 255));
        brush12.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush12);
        QBrush brush13(QColor(255, 255, 220, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush13);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush14(QColor(0, 0, 0, 128));
        brush14.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush14);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QLinearGradient gradient3(0.251, 0.216, 0.811, 0.898);
        gradient3.setSpread(QGradient::ReflectSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0.255556, QColor(0, 128, 218, 255));
        QBrush brush15(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush15);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QLinearGradient gradient4(0.251, 0.216, 0.811, 0.898);
        gradient4.setSpread(QGradient::ReflectSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0.255556, QColor(0, 128, 218, 255));
        QBrush brush16(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush16);
        QLinearGradient gradient5(0.251, 0.216, 0.811, 0.898);
        gradient5.setSpread(QGradient::ReflectSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0.255556, QColor(0, 128, 218, 255));
        QBrush brush17(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush17);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        QBrush brush18(QColor(240, 240, 240, 255));
        brush18.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush18);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush11);
        QBrush brush19(QColor(0, 0, 0, 255));
        brush19.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush19);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush13);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
#endif
        QBrush brush20(QColor(120, 120, 120, 255));
        brush20.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush20);
        QLinearGradient gradient6(0.251, 0.216, 0.811, 0.898);
        gradient6.setSpread(QGradient::ReflectSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0.255556, QColor(0, 128, 218, 255));
        QBrush brush21(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush21);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        QBrush brush22(QColor(247, 247, 247, 255));
        brush22.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush22);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush20);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush20);
        QLinearGradient gradient7(0.251, 0.216, 0.811, 0.898);
        gradient7.setSpread(QGradient::ReflectSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0.255556, QColor(0, 128, 218, 255));
        QBrush brush23(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush23);
        QLinearGradient gradient8(0.251, 0.216, 0.811, 0.898);
        gradient8.setSpread(QGradient::ReflectSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0.255556, QColor(0, 128, 218, 255));
        QBrush brush24(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush24);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush11);
        QBrush brush25(QColor(0, 0, 0, 255));
        brush25.setStyle(Qt::NoBrush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush25);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush13);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        pushButton_login->setPalette(palette);
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(true);
        pushButton_login->setFont(font5);
        pushButton_login->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0.251, y1:0.216, x2:0.811, y2:0.898, stop:0.255556 rgba(0, 128, 218, 255));\n"
"border-radius:10;"));
        label = new QLabel(groupBox_Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 331, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Gotham")});
        font6.setPointSize(24);
        font6.setBold(true);
        label->setFont(font6);
        label->setStyleSheet(QString::fromUtf8("color: rgb(27, 102, 165);"));
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);
        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setGeometry(QRect(0, 0, 130, 50));
        LoginAdmin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginAdmin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 21));
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
        label_hintUsername->setText(QString());
        label_hintPassword->setText(QString());
        pushButton_login->setText(QCoreApplication::translate("LoginAdmin", "LOGIN", nullptr));
        label->setText(QCoreApplication::translate("LoginAdmin", "ADMIN LOGIN", nullptr));
        label_logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginAdmin: public Ui_LoginAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINADMIN_H
