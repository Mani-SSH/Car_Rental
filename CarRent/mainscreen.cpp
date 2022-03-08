#include "mainscreen.h"
#include "ui_mainscreen.h"

extern sql admin;

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);

    /*connect to database*/
    if(admin.db.isOpen()){
        qDebug()<<"Connected...";
    }else{
        /*display error if cannot connect to the database*/
        qDebug()<<"Cannot connect to database";
        QMessageBox::critical(this, "Error", "Cannot connect to the database.");
        QCoreApplication::exit();
    }
}

MainScreen::~MainScreen()
{
    delete ui;
}

/**
 * @brief when text is edited on the line edit where the rate is entered, checks if the entered rate is valid
 * @param arg1
 *
 * arg1 is the string entered in the lineEdit_rate
 * initially sets isValid as true which represents the rate entered is valid
 * loops to check each character of the string entered by the user
 * if the string is not valid (is not a digit), isValid is changed to false and the loop is broken
 * then check if isValid is true or false
 * if isValid is false then disables the add button on the ui of add->car and warns the user
 * if isValid is true then enables the add button on the ui and removes the warning
 */
void MainScreen::on_lineEdit_rate_textEdited(const QString &arg1)
{
    bool isValid = true;   //true if the entered rate is valid

    /*loop to check each character of the string*/
    for(int i = 0; i < arg1.length(); i++)
    {
        /*check if the character is digit*/
        if (!arg1[i].isDigit()){
            /*if not, change isValid to false and break the loop*/
            isValid = false;
            break;
        }
    }

    /*check if the rate is not valid*/
    if(!isValid){
        /*disable the add button on the ui and warn the user*/
        ui->pushButton_addCar->setEnabled(false);
        ui->label_warnRate->setText("<font color='red'>Enter a valid rate");
    }else{
        /*else enable the add button in ui and remove the warning*/
        ui->pushButton_addCar->setEnabled(true);
        ui->label_warnRate->setText("");
    }
}


void MainScreen::on_pushButton_addCar_clicked()
{
    Car ThisCar;
    ThisCar.PlateNum = ui->lineEdit_plateNum->text();
    ThisCar.Brand = ui->lineEdit_brand->text();
    ThisCar.Model = ui->lineEdit_model->text();
    ThisCar.Rate = ui->lineEdit_rate->text().toInt();
    ThisCar.isAvailable = true;
    admin.exportCarDetails(ThisCar);
}

