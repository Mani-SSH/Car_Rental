/********************************************************************************
** Form generated from reading UI file 'mainscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCREEN_H
#define UI_MAINSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScreen
{
public:
    QAction *actionAdd_car;
    QAction *actionAdd_Customer;
    QAction *actionLogout;
    QAction *actionCreate_New_Account;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_Home;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_filterCar;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QTableView *tableView_Cars;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_carSearch;
    QPushButton *pushButton_carSearch;
    QPushButton *pushButton_carFilter;
    QLabel *label_5;
    QComboBox *comboBox_status;
    QLabel *label_6;
    QComboBox *comboBox_range;
    QPushButton *pushButton_carReload;
    QWidget *tab_Customers;
    QWidget *tab_Add;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_addCar;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_plateNum;
    QLabel *label_2;
    QLineEdit *lineEdit_brand;
    QLabel *label_3;
    QLineEdit *lineEdit_model;
    QLabel *label_4;
    QLineEdit *lineEdit_rate;
    QPushButton *pushButton_addCar;
    QLabel *label_warnRate;
    QWidget *tab_addCustomer;
    QGroupBox *groupBox_costumer;
    QLabel *label_fname;
    QLabel *label_lname;
    QLabel *label_phone_no;
    QLabel *label_Lisence;
    QLabel *label_Address;
    QLabel *label_age;
    QLabel *label_ADD_COSTUMER;
    QLineEdit *lineEdit_fname;
    QLineEdit *lineEdit_lname;
    QLineEdit *lineEdit_phone_no;
    QLineEdit *lineEdit_lisence_no;
    QLineEdit *lineEdit_address;
    QLineEdit *lineEdit_age;
    QPushButton *pushButton;
    QRadioButton *radioButton_Male;
    QRadioButton *radioButton_Female;
    QLabel *label_7;
    QRadioButton *radioButton_other;
    QPushButton *pushButton_admin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainScreen)
    {
        if (MainScreen->objectName().isEmpty())
            MainScreen->setObjectName(QString::fromUtf8("MainScreen"));
        MainScreen->resize(1366, 720);
        actionAdd_car = new QAction(MainScreen);
        actionAdd_car->setObjectName(QString::fromUtf8("actionAdd_car"));
        actionAdd_Customer = new QAction(MainScreen);
        actionAdd_Customer->setObjectName(QString::fromUtf8("actionAdd_Customer"));
        actionLogout = new QAction(MainScreen);
        actionLogout->setObjectName(QString::fromUtf8("actionLogout"));
        actionCreate_New_Account = new QAction(MainScreen);
        actionCreate_New_Account->setObjectName(QString::fromUtf8("actionCreate_New_Account"));
        centralwidget = new QWidget(MainScreen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 791, 551));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 1361, 621));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setTabPosition(QTabWidget::West);
        tab_Home = new QWidget();
        tab_Home->setObjectName(QString::fromUtf8("tab_Home"));
        groupBox_2 = new QGroupBox(tab_Home);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 261, 601));
        groupBox_filterCar = new QGroupBox(tab_Home);
        groupBox_filterCar->setObjectName(QString::fromUtf8("groupBox_filterCar"));
        groupBox_filterCar->setGeometry(QRect(290, 60, 701, 551));
        gridLayoutWidget_3 = new QWidget(groupBox_filterCar);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(0, 20, 711, 581));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tableView_Cars = new QTableView(gridLayoutWidget_3);
        tableView_Cars->setObjectName(QString::fromUtf8("tableView_Cars"));

        gridLayout_3->addWidget(tableView_Cars, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab_Home);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(1010, 60, 311, 551));
        groupBox_3 = new QGroupBox(tab_Home);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(290, 0, 1031, 61));
        lineEdit_carSearch = new QLineEdit(groupBox_3);
        lineEdit_carSearch->setObjectName(QString::fromUtf8("lineEdit_carSearch"));
        lineEdit_carSearch->setGeometry(QRect(10, 20, 551, 31));
        pushButton_carSearch = new QPushButton(groupBox_3);
        pushButton_carSearch->setObjectName(QString::fromUtf8("pushButton_carSearch"));
        pushButton_carSearch->setGeometry(QRect(570, 20, 71, 31));
        pushButton_carFilter = new QPushButton(groupBox_3);
        pushButton_carFilter->setObjectName(QString::fromUtf8("pushButton_carFilter"));
        pushButton_carFilter->setGeometry(QRect(650, 20, 71, 31));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(810, 10, 63, 20));
        comboBox_status = new QComboBox(groupBox_3);
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->setObjectName(QString::fromUtf8("comboBox_status"));
        comboBox_status->setGeometry(QRect(810, 30, 101, 21));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(920, 10, 91, 21));
        comboBox_range = new QComboBox(groupBox_3);
        comboBox_range->addItem(QString());
        comboBox_range->addItem(QString());
        comboBox_range->addItem(QString());
        comboBox_range->addItem(QString());
        comboBox_range->setObjectName(QString::fromUtf8("comboBox_range"));
        comboBox_range->setGeometry(QRect(920, 30, 101, 21));
        pushButton_carReload = new QPushButton(groupBox_3);
        pushButton_carReload->setObjectName(QString::fromUtf8("pushButton_carReload"));
        pushButton_carReload->setGeometry(QRect(730, 20, 71, 31));
        tabWidget->addTab(tab_Home, QString());
        tab_Customers = new QWidget();
        tab_Customers->setObjectName(QString::fromUtf8("tab_Customers"));
        tabWidget->addTab(tab_Customers, QString());
        tab_Add = new QWidget();
        tab_Add->setObjectName(QString::fromUtf8("tab_Add"));
        gridLayoutWidget_2 = new QWidget(tab_Add);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 1321, 611));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(gridLayoutWidget_2);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tab_addCar = new QWidget();
        tab_addCar->setObjectName(QString::fromUtf8("tab_addCar"));
        groupBox = new QGroupBox(tab_addCar);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 1311, 571));
        QFont font;
        font.setPointSize(9);
        groupBox->setFont(font);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 711, 162));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_plateNum = new QLineEdit(formLayoutWidget);
        lineEdit_plateNum->setObjectName(QString::fromUtf8("lineEdit_plateNum"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_plateNum);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_brand = new QLineEdit(formLayoutWidget);
        lineEdit_brand->setObjectName(QString::fromUtf8("lineEdit_brand"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_brand);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEdit_model = new QLineEdit(formLayoutWidget);
        lineEdit_model->setObjectName(QString::fromUtf8("lineEdit_model"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_model);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEdit_rate = new QLineEdit(formLayoutWidget);
        lineEdit_rate->setObjectName(QString::fromUtf8("lineEdit_rate"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_rate);

        pushButton_addCar = new QPushButton(groupBox);
        pushButton_addCar->setObjectName(QString::fromUtf8("pushButton_addCar"));
        pushButton_addCar->setGeometry(QRect(30, 210, 83, 29));
        label_warnRate = new QLabel(groupBox);
        label_warnRate->setObjectName(QString::fromUtf8("label_warnRate"));
        label_warnRate->setGeometry(QRect(110, 160, 606, 20));
        QFont font1;
        font1.setPointSize(7);
        label_warnRate->setFont(font1);
        tabWidget_2->addTab(tab_addCar, QString());
        tab_addCustomer = new QWidget();
        tab_addCustomer->setObjectName(QString::fromUtf8("tab_addCustomer"));
        groupBox_costumer = new QGroupBox(tab_addCustomer);
        groupBox_costumer->setObjectName(QString::fromUtf8("groupBox_costumer"));
        groupBox_costumer->setGeometry(QRect(10, 10, 1301, 571));
        label_fname = new QLabel(groupBox_costumer);
        label_fname->setObjectName(QString::fromUtf8("label_fname"));
        label_fname->setGeometry(QRect(110, 65, 131, 21));
        QFont font2;
        font2.setPointSize(16);
        label_fname->setFont(font2);
        label_lname = new QLabel(groupBox_costumer);
        label_lname->setObjectName(QString::fromUtf8("label_lname"));
        label_lname->setGeometry(QRect(510, 65, 111, 21));
        label_lname->setFont(font2);
        label_phone_no = new QLabel(groupBox_costumer);
        label_phone_no->setObjectName(QString::fromUtf8("label_phone_no"));
        label_phone_no->setGeometry(QRect(110, 120, 151, 21));
        label_phone_no->setFont(font2);
        label_Lisence = new QLabel(groupBox_costumer);
        label_Lisence->setObjectName(QString::fromUtf8("label_Lisence"));
        label_Lisence->setGeometry(QRect(110, 160, 181, 31));
        label_Lisence->setFont(font2);
        label_Address = new QLabel(groupBox_costumer);
        label_Address->setObjectName(QString::fromUtf8("label_Address"));
        label_Address->setGeometry(QRect(110, 220, 81, 20));
        label_Address->setFont(font2);
        label_age = new QLabel(groupBox_costumer);
        label_age->setObjectName(QString::fromUtf8("label_age"));
        label_age->setGeometry(QRect(450, 149, 51, 31));
        label_age->setFont(font2);
        label_ADD_COSTUMER = new QLabel(groupBox_costumer);
        label_ADD_COSTUMER->setObjectName(QString::fromUtf8("label_ADD_COSTUMER"));
        label_ADD_COSTUMER->setGeometry(QRect(120, 10, 191, 41));
        QFont font3;
        font3.setPointSize(18);
        label_ADD_COSTUMER->setFont(font3);
        lineEdit_fname = new QLineEdit(groupBox_costumer);
        lineEdit_fname->setObjectName(QString::fromUtf8("lineEdit_fname"));
        lineEdit_fname->setGeometry(QRect(110, 90, 221, 20));
        lineEdit_lname = new QLineEdit(groupBox_costumer);
        lineEdit_lname->setObjectName(QString::fromUtf8("lineEdit_lname"));
        lineEdit_lname->setGeometry(QRect(510, 90, 271, 20));
        lineEdit_phone_no = new QLineEdit(groupBox_costumer);
        lineEdit_phone_no->setObjectName(QString::fromUtf8("lineEdit_phone_no"));
        lineEdit_phone_no->setGeometry(QRect(110, 140, 221, 20));
        lineEdit_lisence_no = new QLineEdit(groupBox_costumer);
        lineEdit_lisence_no->setObjectName(QString::fromUtf8("lineEdit_lisence_no"));
        lineEdit_lisence_no->setGeometry(QRect(110, 190, 221, 20));
        lineEdit_address = new QLineEdit(groupBox_costumer);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));
        lineEdit_address->setGeometry(QRect(110, 240, 221, 20));
        lineEdit_age = new QLineEdit(groupBox_costumer);
        lineEdit_age->setObjectName(QString::fromUtf8("lineEdit_age"));
        lineEdit_age->setGeometry(QRect(510, 150, 113, 20));
        pushButton = new QPushButton(groupBox_costumer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(740, 420, 101, 41));
        radioButton_Male = new QRadioButton(groupBox_costumer);
        radioButton_Male->setObjectName(QString::fromUtf8("radioButton_Male"));
        radioButton_Male->setGeometry(QRect(510, 210, 61, 21));
        QFont font4;
        font4.setPointSize(14);
        radioButton_Male->setFont(font4);
        radioButton_Female = new QRadioButton(groupBox_costumer);
        radioButton_Female->setObjectName(QString::fromUtf8("radioButton_Female"));
        radioButton_Female->setGeometry(QRect(510, 240, 91, 18));
        radioButton_Female->setFont(font4);
        label_7 = new QLabel(groupBox_costumer);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(440, 210, 61, 20));
        label_7->setFont(font2);
        radioButton_other = new QRadioButton(groupBox_costumer);
        radioButton_other->setObjectName(QString::fromUtf8("radioButton_other"));
        radioButton_other->setGeometry(QRect(580, 210, 81, 18));
        radioButton_other->setFont(font4);
        tabWidget_2->addTab(tab_addCustomer, QString());

        gridLayout_2->addWidget(tabWidget_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_Add, QString());
        pushButton_admin = new QPushButton(centralwidget);
        pushButton_admin->setObjectName(QString::fromUtf8("pushButton_admin"));
        pushButton_admin->setGeometry(QRect(0, 640, 80, 24));
        MainScreen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScreen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1366, 17));
        MainScreen->setMenuBar(menubar);
        statusbar = new QStatusBar(MainScreen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainScreen->setStatusBar(statusbar);

        retranslateUi(MainScreen);

        tabWidget->setCurrentIndex(2);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainScreen);
    } // setupUi

    void retranslateUi(QMainWindow *MainScreen)
    {
        MainScreen->setWindowTitle(QCoreApplication::translate("MainScreen", "MainWindow", nullptr));
        actionAdd_car->setText(QCoreApplication::translate("MainScreen", "Add car", nullptr));
        actionAdd_Customer->setText(QCoreApplication::translate("MainScreen", "Add Customer", nullptr));
        actionLogout->setText(QCoreApplication::translate("MainScreen", "Logout", nullptr));
        actionCreate_New_Account->setText(QCoreApplication::translate("MainScreen", "Create New Account", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_filterCar->setTitle(QString());
        groupBox_4->setTitle(QString());
        groupBox_3->setTitle(QString());
        lineEdit_carSearch->setInputMask(QString());
        lineEdit_carSearch->setPlaceholderText(QCoreApplication::translate("MainScreen", "Enter Plate Number of Car", nullptr));
        pushButton_carSearch->setText(QCoreApplication::translate("MainScreen", "Search", nullptr));
        pushButton_carFilter->setText(QCoreApplication::translate("MainScreen", "Filter", nullptr));
        label_5->setText(QCoreApplication::translate("MainScreen", "Status", nullptr));
        comboBox_status->setItemText(0, QCoreApplication::translate("MainScreen", "Available", nullptr));
        comboBox_status->setItemText(1, QCoreApplication::translate("MainScreen", "Rented", nullptr));

        label_6->setText(QCoreApplication::translate("MainScreen", "Price range", nullptr));
        comboBox_range->setItemText(0, QCoreApplication::translate("MainScreen", "All", nullptr));
        comboBox_range->setItemText(1, QCoreApplication::translate("MainScreen", "< 1000", nullptr));
        comboBox_range->setItemText(2, QCoreApplication::translate("MainScreen", "1000 - 2000", nullptr));
        comboBox_range->setItemText(3, QCoreApplication::translate("MainScreen", "2000+", nullptr));

        pushButton_carReload->setText(QCoreApplication::translate("MainScreen", "Reload", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Home), QCoreApplication::translate("MainScreen", "Home", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Customers), QCoreApplication::translate("MainScreen", "Customers", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainScreen", "Plater Number", nullptr));
        label_2->setText(QCoreApplication::translate("MainScreen", "Brand", nullptr));
        label_3->setText(QCoreApplication::translate("MainScreen", "Model", nullptr));
        label_4->setText(QCoreApplication::translate("MainScreen", "Rate", nullptr));
        pushButton_addCar->setText(QCoreApplication::translate("MainScreen", "ADD", nullptr));
        label_warnRate->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_addCar), QCoreApplication::translate("MainScreen", "Car", nullptr));
        groupBox_costumer->setTitle(QString());
        label_fname->setText(QCoreApplication::translate("MainScreen", "First Name", nullptr));
        label_lname->setText(QCoreApplication::translate("MainScreen", "Last Name", nullptr));
        label_phone_no->setText(QCoreApplication::translate("MainScreen", "Phone Number", nullptr));
        label_Lisence->setText(QCoreApplication::translate("MainScreen", "License Number", nullptr));
        label_Address->setText(QCoreApplication::translate("MainScreen", "Address", nullptr));
        label_age->setText(QCoreApplication::translate("MainScreen", "Age", nullptr));
        label_ADD_COSTUMER->setText(QCoreApplication::translate("MainScreen", "ADD CUSTOMER", nullptr));
        pushButton->setText(QCoreApplication::translate("MainScreen", "ADD Customer", nullptr));
        radioButton_Male->setText(QCoreApplication::translate("MainScreen", "Male", nullptr));
        radioButton_Female->setText(QCoreApplication::translate("MainScreen", "Female", nullptr));
        label_7->setText(QCoreApplication::translate("MainScreen", "Gender", nullptr));
        radioButton_other->setText(QCoreApplication::translate("MainScreen", "Other", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_addCustomer), QCoreApplication::translate("MainScreen", "Customer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Add), QCoreApplication::translate("MainScreen", "Add", nullptr));
        pushButton_admin->setText(QCoreApplication::translate("MainScreen", "Admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScreen: public Ui_MainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCREEN_H
