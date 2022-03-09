/********************************************************************************
** Form generated from reading UI file 'admin_info.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_INFO_H
#define UI_ADMIN_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_admin_info
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit_fname;
    QLineEdit *lineEdit_Lname;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_confirm_password;
    QLabel *label_f_name;
    QLabel *label_Lname;
    QLabel *label_username;
    QLabel *label_password;
    QLabel *label_confirm_password;
    QLabel *label_ADD_USER;
    QLabel *label_username_check;
    QLabel *label_password_check;
    QCheckBox *checkBox;

    void setupUi(QDialog *admin_info)
    {
        if (admin_info->objectName().isEmpty())
            admin_info->setObjectName(QString::fromUtf8("admin_info"));
        admin_info->resize(522, 432);
        groupBox = new QGroupBox(admin_info);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 0, 481, 411));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(390, 350, 80, 51));
        lineEdit_fname = new QLineEdit(groupBox);
        lineEdit_fname->setObjectName(QString::fromUtf8("lineEdit_fname"));
        lineEdit_fname->setGeometry(QRect(150, 100, 251, 20));
        lineEdit_Lname = new QLineEdit(groupBox);
        lineEdit_Lname->setObjectName(QString::fromUtf8("lineEdit_Lname"));
        lineEdit_Lname->setGeometry(QRect(150, 140, 251, 20));
        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(190, 190, 113, 20));
        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(190, 230, 113, 20));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        lineEdit_confirm_password = new QLineEdit(groupBox);
        lineEdit_confirm_password->setObjectName(QString::fromUtf8("lineEdit_confirm_password"));
        lineEdit_confirm_password->setEnabled(true);
        lineEdit_confirm_password->setGeometry(QRect(190, 270, 113, 20));
        lineEdit_confirm_password->setEchoMode(QLineEdit::Password);
        label_f_name = new QLabel(groupBox);
        label_f_name->setObjectName(QString::fromUtf8("label_f_name"));
        label_f_name->setGeometry(QRect(50, 100, 101, 20));
        QFont font;
        font.setPointSize(12);
        label_f_name->setFont(font);
        label_Lname = new QLabel(groupBox);
        label_Lname->setObjectName(QString::fromUtf8("label_Lname"));
        label_Lname->setGeometry(QRect(50, 140, 91, 20));
        label_Lname->setFont(font);
        label_username = new QLabel(groupBox);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        label_username->setGeometry(QRect(80, 190, 101, 20));
        label_username->setFont(font);
        label_password = new QLabel(groupBox);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setGeometry(QRect(80, 230, 91, 20));
        label_password->setFont(font);
        label_confirm_password = new QLabel(groupBox);
        label_confirm_password->setObjectName(QString::fromUtf8("label_confirm_password"));
        label_confirm_password->setGeometry(QRect(30, 270, 141, 20));
        label_confirm_password->setFont(font);
        label_ADD_USER = new QLabel(groupBox);
        label_ADD_USER->setObjectName(QString::fromUtf8("label_ADD_USER"));
        label_ADD_USER->setGeometry(QRect(210, 10, 111, 41));
        QFont font1;
        font1.setPointSize(18);
        label_ADD_USER->setFont(font1);
        label_username_check = new QLabel(groupBox);
        label_username_check->setObjectName(QString::fromUtf8("label_username_check"));
        label_username_check->setGeometry(QRect(310, 190, 121, 16));
        label_password_check = new QLabel(groupBox);
        label_password_check->setObjectName(QString::fromUtf8("label_password_check"));
        label_password_check->setGeometry(QRect(310, 270, 161, 16));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(260, 300, 111, 18));

        retranslateUi(admin_info);
        QObject::connect(checkBox, &QCheckBox::toggled, lineEdit_confirm_password, &QLineEdit::setEnabled);
        QObject::connect(checkBox, &QCheckBox::toggled, lineEdit_password, &QLineEdit::setEnabled);

        QMetaObject::connectSlotsByName(admin_info);
    } // setupUi

    void retranslateUi(QDialog *admin_info)
    {
        admin_info->setWindowTitle(QCoreApplication::translate("admin_info", "Dialog", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QCoreApplication::translate("admin_info", "ADD", nullptr));
        label_f_name->setText(QCoreApplication::translate("admin_info", "First Name", nullptr));
        label_Lname->setText(QCoreApplication::translate("admin_info", "Last Name", nullptr));
        label_username->setText(QCoreApplication::translate("admin_info", "Username", nullptr));
        label_password->setText(QCoreApplication::translate("admin_info", "Password", nullptr));
        label_confirm_password->setText(QCoreApplication::translate("admin_info", "Confirm Password", nullptr));
        label_ADD_USER->setText(QCoreApplication::translate("admin_info", "ADD USER", nullptr));
        label_username_check->setText(QString());
        label_password_check->setText(QString());
        checkBox->setText(QCoreApplication::translate("admin_info", "Show password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin_info: public Ui_admin_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_INFO_H
