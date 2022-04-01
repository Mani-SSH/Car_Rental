#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "costumer.h"
#include "car.h"

extern sql admin;
extern bool isLoggedIn;
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


    /*adding background image color in main window*/
    QPixmap bkgnd(":/resources/img/mainscreen.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);


    /*initialize table of cars*/
    ui->tableView_Cars->setModel(admin.filterTablecars(true, 0, INT_MAX, false));


    //adding icons in search bars
    QIcon search(":/resources/img/search.png");
    ui->lineEdit_carSearch->addAction(search,QLineEdit::LeadingPosition);

    /*adding photo in customer add page*/
    QPixmap customerAdd(":/resources/img/addCustomer.png");
    ui->label_addcusphoto->setPixmap(customerAdd);
    ui->label_addcusphoto->setScaledContents(true);
    ui->label_addcusphoto->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    /*adding photo in add image label*/
    QPixmap dummyImg(":/resources/img/dummy car img.jpg");
    ui->label_image->setPixmap(dummyImg);
    ui->label_image->setScaledContents(true);
    ui->label_image->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

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

    /*if the lineEdits are empty*/
    if(ThisCar.PlateNum == "" || ThisCar.Brand == "" || ThisCar.Model == "" || ThisCar.Rate == 0){
        /*display error message*/
        QMessageBox::critical(this, "Error", "Please enter all the required informataion.");
    }else{
        /*check if the car with given plate number exists*/
        if (admin.carExists(ThisCar.PlateNum)){
            /*give a error message*/
            QMessageBox::critical(this, "Error", "The car with the given plate number already exists.");
        }else{
            /*export the data to the database and inform the user*/
            admin.exportCarDetails(ThisCar);
            QMessageBox::information(this, "Data added", "Car has been added to the database.");

            /*clear the add cars form*/
            ui->lineEdit_plateNum->setText("");
            ui->lineEdit_brand->setText("");
            ui->lineEdit_model->setText("");
            ui->lineEdit_rate->setText("");

            /*reload table of cars*/
            ui->tableView_Cars->setModel(admin.filterTablecars(true, 0, INT_MAX, false));
        }
    }
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
    ui->tableView_Cars->setModel(admin.filterTablecars(true, 0, INT_MAX, false));
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
 * in comboBox_sortCar,
 * currentIndex() is 0 when the combo box is set on "Descending" option
 * currentIndex() is 1 when the combo box is set on "Ascending" option
 *
 * isAvailable stores the value based on combobox_status
 * lowerRange & upperRange stores the values based on combobox_range
 * isAscending stores the value based on comboBox_sortCar
 *
 * loads the table with help of values stored in isAvailable, lowerRange, upperRange and isAscending
 */
void MainScreen::on_pushButton_carFilter_clicked()
{
    bool isAvailable = true;                  //status of cars
    int lowerRange = 0, upperRange = INT_MAX; //price range of cars
    bool isAscendingOrder = false;

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

    /*if comboBox_sortCar is set on "Desending" option*/
    if(ui->comboBox_sortCar->currentIndex() == 0){
        isAscendingOrder = false;
    }else{
        isAscendingOrder = true;
    }

    /*load table of cars*/
    ui->tableView_Cars->setModel(admin.filterTablecars(isAvailable, lowerRange, upperRange, isAscendingOrder));
}


void MainScreen::on_pushButton_admin_clicked()
{

    /*open dialog to admin window*/
    change_admin Change_admin;
    Change_admin.setModal(true);
    Change_admin.exec();
    if(!isLoggedIn){
        this->close();
    }
}


void MainScreen::on_pushButton_clicked()
{
    Costumer Thiscostumer;
    Thiscostumer.C_fname = ui->lineEdit_fnameh->text();
    Thiscostumer.C_lname = ui->lineEdit_lname->text();
    Thiscostumer.phone_no = ui->lineEdit_phone_no->text();
    Thiscostumer.lisence_no = ui->lineEdit_lisence_no->text();
    Thiscostumer.age = ui->lineEdit_age->text().toInt();
    Thiscostumer.Address = ui->lineEdit_address->text();
    if(ui->radioButton_Male->isChecked())
    {
        Thiscostumer.gender = "Male";
    }
    if (ui->radioButton_Female->isChecked())
    {
        Thiscostumer.gender = "Female";
    }
    if (ui->radioButton_other->isChecked())
    {
        Thiscostumer.gender = "Other";
    }
    admin.exportCostumer(Thiscostumer);
    QMessageBox::information(this, "Data added", "Costumer has been added to the database.");
}


void MainScreen::on_pushButton_Search_clicked()
{
    QString searchText;
    bool isPhone;
    Costumer thisCostumer;
    searchText = ui->lineEdit_searchbar->text();
    if (ui->comboBox_costumer->currentIndex() == 0)
    {
        isPhone = true;
    }
    else
    {
        isPhone = false;
    }
    thisCostumer = admin.importCostumer(searchText,isPhone);
    ui->tableView_customer->setModel(admin.searchTableCostumer(searchText,isPhone));
    ui->label_sql_fname->setText(thisCostumer.C_fname);
    ui->label_sql_lname->setText(thisCostumer.C_lname);
    ui->label_sql_age->setText(QString::number(thisCostumer.age));
    ui->label_sql_gender->setText(thisCostumer.gender);
    ui->label_sql_phone->setText(thisCostumer.phone_no);
    ui->label_sql_lisence->setText(thisCostumer.lisence_no);
    ui->label_sql_address->setText(thisCostumer.Address);
}

/*this button requests user to add picture of the car to be added
*here, when button is pushed, option to choose the file is prompt
*the path is saved in "image"
*/
void MainScreen::on_pushButton_2_clicked()
{
    QString file_path=QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpg *.jpeg *bmp"));
    if(QString::compare(file_path,QString())!=0)
    {
        QImage image;
        bool valid=image.load(file_path);

        if (valid)
        {
            image=image.scaledToWidth(ui->label_image->width(), Qt::SmoothTransformation);
            ui->label_image->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //Error handling
        }
    }

}

