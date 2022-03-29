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
    QGroupBox *groupBox_5;
    QLabel *label_Add_costumer;
    QLabel *label_fname;
    QLabel *label_lname;
    QLineEdit *lineEdit_fname;
    QLineEdit *lineEdit_lname;
    QLineEdit *lineEdit_phone_no;
    QLabel *label_Phone_no;
    QLabel *label_Address;
    QLineEdit *lineEdit_Address;
    QLineEdit *lineEdit_Age;
    QLineEdit *lineEdit_Lisence_no;
    QLabel *label_Age;
    QLabel *label_lisence_no;
    QPushButton *pushButton;
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
        groupBox_5 = new QGroupBox(tab_Customers);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(-10, 0, 1301, 591));
        label_Add_costumer = new QLabel(groupBox_5);
        label_Add_costumer->setObjectName(QString::fromUtf8("label_Add_costumer"));
        label_Add_costumer->setGeometry(QRect(550, 10, 191, 61));
        QFont font;
        font.setPointSize(24);
        label_Add_costumer->setFont(font);
        label_fname = new QLabel(groupBox_5);
        label_fname->setObjectName(QString::fromUtf8("label_fname"));
        label_fname->setGeometry(QRect(340, 145, 131, 21));
        QFont font1;
        font1.setPointSize(16);
        label_fname->setFont(font1);
        label_lname = new QLabel(groupBox_5);
        label_lname->setObjectName(QString::fromUtf8("label_lname"));
        label_lname->setGeometry(QRect(730, 150, 111, 16));
        label_lname->setFont(font1);
        lineEdit_fname = new QLineEdit(groupBox_5);
        lineEdit_fname->setObjectName(QString::fromUtf8("lineEdit_fname"));
        lineEdit_fname->setGeometry(QRect(340, 170, 271, 21));
        lineEdit_lname = new QLineEdit(groupBox_5);
        lineEdit_lname->setObjectName(QString::fromUtf8("lineEdit_lname"));
        lineEdit_lname->setGeometry(QRect(730, 170, 281, 21));
        lineEdit_phone_no = new QLineEdit(groupBox_5);
        lineEdit_phone_no->setObjectName(QString::fromUtf8("lineEdit_phone_no"));
        lineEdit_phone_no->setGeometry(QRect(340, 240, 271, 20));
        label_Phone_no = new QLabel(groupBox_5);
        label_Phone_no->setObjectName(QString::fromUtf8("label_Phone_no"));
        label_Phone_no->setGeometry(QRect(340, 220, 131, 16));
        label_Phone_no->setFont(font1);
        label_Address = new QLabel(groupBox_5);
        label_Address->setObjectName(QString::fromUtf8("label_Address"));
        label_Address->setGeometry(QRect(340, 280, 111, 16));
        label_Address->setFont(font1);
        lineEdit_Address = new QLineEdit(groupBox_5);
        lineEdit_Address->setObjectName(QString::fromUtf8("lineEdit_Address"));
        lineEdit_Address->setGeometry(QRect(340, 300, 271, 20));
        lineEdit_Age = new QLineEdit(groupBox_5);
        lineEdit_Age->setObjectName(QString::fromUtf8("lineEdit_Age"));
        lineEdit_Age->setGeometry(QRect(340, 350, 113, 20));
        lineEdit_Lisence_no = new QLineEdit(groupBox_5);
        lineEdit_Lisence_no->setObjectName(QString::fromUtf8("lineEdit_Lisence_no"));
        lineEdit_Lisence_no->setGeometry(QRect(730, 230, 281, 20));
        label_Age = new QLabel(groupBox_5);
        label_Age->setObjectName(QString::fromUtf8("label_Age"));
        label_Age->setGeometry(QRect(340, 330, 37, 21));
        label_Age->setFont(font1);
        label_lisence_no = new QLabel(groupBox_5);
        label_lisence_no->setObjectName(QString::fromUtf8("label_lisence_no"));
        label_lisence_no->setGeometry(QRect(730, 210, 151, 16));
        label_lisence_no->setFont(font1);
        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(980, 530, 80, 41));
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
        QFont font2;
        font2.setPointSize(9);
        groupBox->setFont(font2);
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
        QFont font3;
        font3.setPointSize(7);
        label_warnRate->setFont(font3);
        tabWidget_2->addTab(tab_addCar, QString());
        tab_addCustomer = new QWidget();
        tab_addCustomer->setObjectName(QString::fromUtf8("tab_addCustomer"));
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

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);


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
        groupBox_5->setTitle(QString());
        label_Add_costumer->setText(QCoreApplication::translate("MainScreen", "ADD COSTUMER", nullptr));
        label_fname->setText(QCoreApplication::translate("MainScreen", "First Name", nullptr));
        label_lname->setText(QCoreApplication::translate("MainScreen", "Last Name", nullptr));
        label_Phone_no->setText(QCoreApplication::translate("MainScreen", "Phone Number", nullptr));
        label_Address->setText(QCoreApplication::translate("MainScreen", "Address", nullptr));
        label_Age->setText(QCoreApplication::translate("MainScreen", "Age", nullptr));
        label_lisence_no->setText(QCoreApplication::translate("MainScreen", "License Number", nullptr));
        pushButton->setText(QCoreApplication::translate("MainScreen", "ADD", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Customers), QCoreApplication::translate("MainScreen", "Customers", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainScreen", "Plater Number", nullptr));
        label_2->setText(QCoreApplication::translate("MainScreen", "Brand", nullptr));
        label_3->setText(QCoreApplication::translate("MainScreen", "Model", nullptr));
        label_4->setText(QCoreApplication::translate("MainScreen", "Rate", nullptr));
        pushButton_addCar->setText(QCoreApplication::translate("MainScreen", "ADD", nullptr));
        label_warnRate->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_addCar), QCoreApplication::translate("MainScreen", "Car", nullptr));
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
