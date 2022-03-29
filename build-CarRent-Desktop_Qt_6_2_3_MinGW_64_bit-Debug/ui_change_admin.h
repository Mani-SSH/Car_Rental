/********************************************************************************
** Form generated from reading UI file 'change_admin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_ADMIN_H
#define UI_CHANGE_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_change_admin
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2_addAccount;
    QLabel *label_3_logout;
    QPushButton *pushButton_addAccount;
    QPushButton *pushButton_logout;

    void setupUi(QDialog *change_admin)
    {
        if (change_admin->objectName().isEmpty())
            change_admin->setObjectName(QString::fromUtf8("change_admin"));
        change_admin->resize(400, 300);
        verticalLayout = new QVBoxLayout(change_admin);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(change_admin);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 221, 16));
        label_2_addAccount = new QLabel(groupBox);
        label_2_addAccount->setObjectName(QString::fromUtf8("label_2_addAccount"));
        label_2_addAccount->setGeometry(QRect(50, 70, 121, 16));
        label_3_logout = new QLabel(groupBox);
        label_3_logout->setObjectName(QString::fromUtf8("label_3_logout"));
        label_3_logout->setGeometry(QRect(260, 70, 49, 16));
        pushButton_addAccount = new QPushButton(groupBox);
        pushButton_addAccount->setObjectName(QString::fromUtf8("pushButton_addAccount"));
        pushButton_addAccount->setGeometry(QRect(50, 120, 80, 24));
        pushButton_logout = new QPushButton(groupBox);
        pushButton_logout->setObjectName(QString::fromUtf8("pushButton_logout"));
        pushButton_logout->setGeometry(QRect(250, 120, 80, 24));

        verticalLayout->addWidget(groupBox);


        retranslateUi(change_admin);

        QMetaObject::connectSlotsByName(change_admin);
    } // setupUi

    void retranslateUi(QDialog *change_admin)
    {
        change_admin->setWindowTitle(QCoreApplication::translate("change_admin", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("change_admin", "Choose any of the action:", nullptr));
        label_2_addAccount->setText(QCoreApplication::translate("change_admin", "ADD ACCOUNT", nullptr));
        label_3_logout->setText(QCoreApplication::translate("change_admin", "LOG OUT", nullptr));
        pushButton_addAccount->setText(QCoreApplication::translate("change_admin", "ADD", nullptr));
        pushButton_logout->setText(QCoreApplication::translate("change_admin", "LOGOUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change_admin: public Ui_change_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_ADMIN_H
