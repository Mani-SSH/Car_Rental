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






void MainScreen::on_lineEdit_rate_textEdited(const QString &arg1)
{
    bool isValid = true;
    for(int i = 0; i < arg1.length(); i++)
    {
        if (!arg1[i].isDigit()){
            isValid = false;
            break;
        }
    }

    if(!isValid){
        ui->pushButton_addCar->setEnabled(false);
        ui->label_warnRate->setText("<font color='red'>Enter a valid rate");
    }else{
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
}

