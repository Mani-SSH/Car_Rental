#include "mainscreen.h"
#include "ui_mainscreen.h"

extern sql admin;

MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);

    /*check if connected to database*/
    if(admin.db.isOpen()){
        qDebug()<<"Connected...";
    }else{
        /*display error if is not connect to the database*/
        qDebug()<<"Cannot connect to database";
        QMessageBox::critical(this, "Error", "Cannot connect to the database.");
        QCoreApplication::exit();
    }

    /*initialize table of cars*/
    ui->tableView_Cars->setModel(admin.filterTablecars(true, 0, INT_MAX));
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


/**
 * @brief if add button is clicked in add->car, adds the car details to the database taken from the user
 *
 * makes an object of class Car
 * stores the values given by the user in the object
 * exports the data in the object to the database and inform the user with a messagebox
 * reloads the table in the application
 */
void MainScreen::on_pushButton_addCar_clicked()
{
    /*make an object of class Car and take data from user taken from the database*/
    Car ThisCar;
    ThisCar.PlateNum = ui->lineEdit_plateNum->text();
    ThisCar.Brand = ui->lineEdit_brand->text();
    ThisCar.Model = ui->lineEdit_model->text();
    ThisCar.Rate = ui->lineEdit_rate->text().toInt();
    ThisCar.isAvailable = true;

    /*export the data to the database and inform the user*/
    admin.exportCarDetails(ThisCar);
    QMessageBox::information(this, "Data added", "Car has been added to the database.");

    /*reload table of cars*/
    ui->tableView_Cars->setModel(admin.filterTablecars(true, 0, INT_MAX));
}


/**
 * @brief shows data of the car clicked on the table and prepares the rent form
 * @param index
 *
 * INCOMPLETE
 */
void MainScreen::on_tableView_Cars_activated(const QModelIndex &index)
{
    QString val = ui->tableView_Cars->model()->data(index).toString();

}


/**
 * @brief searches the car with help of plate number entered by user in lineEdit_carSearch
 *
 * stores the plate number entered by the user in platenumber
 * gets an QSqlQueryModel with searchTablecars() and set the model in tableView_Cars
 */
void MainScreen::on_pushButton_carSearch_clicked()
{
    QString platenumber = ui->lineEdit_carSearch->text();
    ui->tableView_Cars->setModel(admin.searchTablecars(platenumber));
}


/**
 * @brief reloads table with default values
 */
void MainScreen::on_pushButton_carReload_clicked()
{
    /*reload table of cars*/
    ui->tableView_Cars->setModel(admin.filterTablecars(true, 0, INT_MAX));
}


/**
 * @brief filters the table with the filters int the combo box
 *
 * in comboBox_status,
 * currentIndex() is 0 when the combo box is set on "Available" option
 * currentIndex() is 1 when the combo box is set on "Rented" option
 *
 * in comboBox_range.
 * currentIndex() is 0 when the combo box is set on "All" option
 * currentIndex() is 1 when the combo box is set on "< 1000" option
 * currentIndex() is 2 when the combo box is set on "1000 - 2000" option
 * currentIndex() is 3 when the combo box is set on "2000+" option
 *
 * isAvailable stores the value based on combobox_status
 * lowerRange & upperRange stores the values based on combobox_range
 *
 * loads the table with help of values stored in isAvailable, lowerRange and upperRange
 */
void MainScreen::on_pushButton_carFilter_clicked()
{
    bool isAvailable = true;                  //status of cars
    int lowerRange = 0, upperRange = INT_MAX; //price range of cars

    /*if comboBox_status is set on "Available" option*/
    if(ui->comboBox_status->currentIndex() == 0){
        /*set isAvailable as true*/
        isAvailable = true;
    }else{
        /*set isAvailable as false*/
        isAvailable = false;
    }

    /*find what is the value of currentindex() of comboBox_range*/
    switch(ui->comboBox_range->currentIndex())
    {
    case 0:
        /*if comboBox_range is set on "All" option*/
        lowerRange = 0;
        upperRange = INT_MAX;
        break;
    case 1:
        /*if comboBox_range is set on "< 1000" option*/
        lowerRange = 0;
        upperRange = 1000;
        break;
    case 2:
        /*if comboBox_range is set on "1000 - 2000" option*/
        lowerRange = 1000;
        upperRange = 2000;
        break;
    case 3:
        /*if comboBox_range is set on "2000+" option*/
        lowerRange = 2000;
        upperRange = INT_MAX;
        break;
    }

    /*load table of cars*/
    ui->tableView_Cars->setModel(admin.filterTablecars(isAvailable, lowerRange, upperRange));
}

