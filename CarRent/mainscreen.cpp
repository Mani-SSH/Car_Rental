#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "costumer.h"
#include "car.h"

extern sql admin;
extern bool isLoggedIn;
extern account user;

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

    /*welcome user*/
    ui->label_welcomeUser->setText("Welcome! " + user.f_name + " " + user.l_name + ".");

    /*adding background image color in main window*/
    QPixmap bkgnd(":/resources/img/mainscreen.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    /*make dateEdit able to use Calendar Popup*/
    ui->dateEdit_rentDate->setCalendarPopup(true);
    ui->dateEdit_rentReturnDate->setCalendarPopup(true);
    ui->dateEdit_DateoBirth->setCalendarPopup(true);

    ui->tableView_customer->setModel(admin.filterTableCostumer(0));

    //adding icons in search bars
    QIcon search(":/resources/img/search.png");
    ui->lineEdit_carSearch->addAction(search,QLineEdit::LeadingPosition);

    ui->lineEdit_searchbar->addAction(search,QLineEdit::LeadingPosition);

    /*adding photo in customer add page*/
    QPixmap customerAdd(":/resources/img/addCustomer.png");
    ui->label_addcusphoto->setPixmap(customerAdd);
    ui->label_addcusphoto->setScaledContents(true);
    ui->label_addcusphoto->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    /*adding photo in add image label*/
    QPixmap dummyImg(":/resources/img/dummy car img-01.jpg");
    ui->label_image->setPixmap(dummyImg);
    ui->label_image->setScaledContents(true);
    ui->label_image->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    /*adding photo in label_carPhoto*/
    ui->label_carPhoto->setPixmap(dummyImg);
    ui->label_carPhoto->setScaledContents(true);
    ui->label_carPhoto->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    /*adding admin icon*/
    ui->pushButton_admin->setIcon(QIcon(":/resources/img/admin_icon.png"));

    /*initialize home tab*/
    initializeHomeTab();
}


MainScreen::~MainScreen()
{
    delete ui;
}

void MainScreen::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/resources/img/blue.png");
    painter.drawPixmap(0,0,pix);

}

void MainScreen::initializeHomeTab()
{
    carClicked = Car();

    /*reload search, filter and table*/
    on_pushButton_carReload_clicked();

    /*initialize lineEdits*/
    ui->lineEdit_rentPhoneNum->setText("");
    ui->lineEdit_rentPlateNum->setText("");
    ui->lineEdit_rentCost->setText("0");

    /*reset dateEdits*/
    ui->dateEdit_rentDate->setDate(QDate::currentDate());
    ui->dateEdit_rentReturnDate->setDate(QDate::currentDate().addDays(1));
    ui->lineEdit_rentDays->setText(QString::number(Car::calculateDaysRented(QDate::currentDate(), QDate::currentDate().addDays(1))));

    initializeCarDisplay();
}


void MainScreen::initializeCarDisplay()
{
    /*disable return and delete button in display section in home tab*/
    ui->pushButton_carReturn->setEnabled(false);
    ui->pushButton_carDelete->setEnabled(false);

    /*intialize labels*/
    ui->label_showPlateNum->setText("");
    ui->label_showBrand->setText("");
    ui->label_showModel->setText("");
    ui->label_showRate->setText("");
    ui->label_showStatus->setText("");
    ui->label_showCustomer->setText("");
    ui->label_showDateRented->setText("");
    ui->label_showDateToReturn->setText("");

    /*show defalult car icon*/

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
        }else{
            try {
                int x = arg1.toInt();
                if (x > 9999999)
                    throw (x);
            }  catch (int x) {
                isValid = false;
                break;
            }
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
    /*take data from user*/
    carToAdd.PlateNum = ui->lineEdit_plateNum->text();
    carToAdd.Brand = ui->lineEdit_brand->text();
    carToAdd.Model = ui->lineEdit_model->text();
    carToAdd.Rate = ui->lineEdit_rate->text().toInt();
    carToAdd.isAvailable = true;

    /*if the lineEdits are empty*/
    if(carToAdd.PlateNum == "" || carToAdd.Brand == "" || carToAdd.Model == "" || carToAdd.Rate == 0){
        /*display error message*/
        QMessageBox::critical(this, "Error", "Please enter all the required informataion.");
    }else{
        /*check if the car with given plate number exists*/
        if (admin.carExists(carToAdd.PlateNum)){
            /*give a error message*/
            QMessageBox::critical(this, "Error", "The car with the given plate number already exists.");
        }else{
            /*export the data to the database and inform the user*/
            admin.exportCarDetails(carToAdd);



            QMessageBox::information(this, "Data added", "Car has been added to the database.");

            carToAdd=Car();

            /*clear the add cars form*/
            ui->lineEdit_plateNum->setText("");
            ui->lineEdit_brand->setText("");
            ui->lineEdit_model->setText("");
            ui->lineEdit_rate->setText("");
            /*adding photo in add image label*/
            QPixmap dummyImg(":/resources/img/dummy car img-01.jpg");
            ui->label_image->setPixmap(dummyImg);
            ui->label_image->setScaledContents(true);
            ui->label_image->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

            /*reload table of cars*/
            ui->tableView_Cars->setModel(admin.filterTablecars(true, 0, INT_MAX, false));
        }
    }
}


/*this button requests user to add picture of the car to be added
*here, when button is pushed, option to choose the file is prompt
*the path is saved in "image"
*/
void MainScreen::on_pushButton_2_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images(*.png *.jpg *.jpeg *bmp"));
    if(QString::compare(file_path,QString())!=0)
    {
        QImage image;
        bool valid = image.load(file_path);

        if (valid)
        {
            image = image.scaledToWidth(ui->label_image->width(), Qt::SmoothTransformation);
            ui->label_image->setPixmap(QPixmap::fromImage(image));
            carToAdd.PhotoPath = file_path;
        }
        else
        {
            carToAdd.PhotoPath=":/resources/img/dummy car img-01.jpg";
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
    /*take the string of the element double clicked in table*/
    QString val = ui->tableView_Cars->model()->data(index).toString();

    /*if the element clicked on the table is the plate number of the car*/
    if(admin.carExists(val)){
        /*import all the information of the car*/
        carClicked = admin.importCar(val);

        /*display them on the display section of the car tab*/
        displayCar(carClicked);

        /*initialize rent form*/
        initializeRentCar(carClicked);

        showCost(carClicked);
    }

}


/**
 * @brief sets text for lineEdit_rentPlateNum as the plate number of car x
 * @param x
 */
void MainScreen::initializeRentCar(Car x)
{
    ui->lineEdit_rentPlateNum->setText(x.PlateNum);
}


void MainScreen::showCost(Car x)
{
    int days = ui->lineEdit_rentDays->text().toInt();
    ui->lineEdit_rentCost->setText(QString::number(days * x.Rate));
}


/**
 * @brief display information of the car x on the display section of the car tab
 * @param x
 *
 * uses labels in the display section to display data
 */
void MainScreen::displayCar(Car x)
{
    /*set text in plate number, brand, model, rate and set image of the car */
    ui->label_showPlateNum->setText(x.PlateNum);
    ui->label_showBrand->setText(x.Brand);
    ui->label_showModel->setText(x.Model);
    ui->label_showRate->setText(QString::number(x.Rate));
    QImage image;
    bool valid = image.load(x.PhotoPath);

    if (valid)
    {
        image = image.scaledToWidth(ui->label_carPhoto->width(), Qt::SmoothTransformation);
        ui->label_carPhoto->setPixmap(QPixmap::fromImage(image));
    }
    else
    {
        image.load(":/resources/img/dummy car img-01.jpg");
        image = image.scaledToWidth(ui->label_carPhoto->width(), Qt::SmoothTransformation);
        ui->label_carPhoto->setPixmap(QPixmap::fromImage(image));
    }

    /*check if car is available for renting*/
    if(x.isAvailable){
        /*show status available*/
        ui->label_showStatus->setText("<font color='green'>Available");

        /*enable return and delete button in display section in home tab*/
        ui->pushButton_carReturn->setEnabled(false);
        ui->pushButton_carDelete->setEnabled(true);
    }else{
        /*show status rented and show customers phone number, rented date and date to return*/
        ui->label_showStatus->setText("<font color='red'>Rented");
        ui->label_showCustomer->setText(x.phone_no);
        ui->label_showDateRented->setText(x.DateRented.toString());
        ui->label_showDateToReturn->setText(x.DateToReturn.toString());

        /*disable return and delete button in display section in home tab*/
        ui->pushButton_carReturn->setEnabled(true);
        ui->pushButton_carDelete->setEnabled(false);
    }
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

    /*reset combo box*/
    ui->comboBox_status->setCurrentIndex(0);
    ui->comboBox_sortCar->setCurrentIndex(0);
    ui->comboBox_range->setCurrentIndex(0);

    ui->lineEdit_carSearch->setText("");
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


/**
 * @brief when rent button is clicked
 *
 * takes plate number, cost and phone number from the user
 * if the lineEdits were not empty, displays error message
 * if not, check if the car with the given plate number exists
 * if no, displays error message
 * if yes, check if the customer with the given phone number exists
 * if no, displays error message
 * if yes, imports data of the given in an object of class Car
 * then, checks if the car is available to rent
 * if no, display error message
 * if yes, stores the given data in the object of class Car
 * rents the car and gives a message to user
 */
void MainScreen::on_pushButton_rent_clicked()
{
    /*get values from the user*/
    QString PlateNum = ui->lineEdit_rentPlateNum->text();
    QString phone_no = ui->lineEdit_rentPhoneNum->text();
    int Cost = ui->lineEdit_rentCost->text().toInt();

    /*check if the lineEdits were not empty*/
    if(PlateNum == "" || phone_no == "" || Cost == 0){

        /*if empty, display error message*/
        QMessageBox::critical(this, "Error", "Please enter all the required informataion.");
    }else{

        /*check if the car with the given plate number exist*/
        if(admin.carExists(PlateNum)){

            /*check if the customer with the given phone number exist*/
            if(admin.costumerExists(phone_no)){

                /*import data of the given in an object of class Car*/
                Car ThisCar = admin.importCar(PlateNum);

                /*check if the car is available to rent*/
                if(ThisCar.isAvailable){

                    /*store the given data in the object of class Car*/
                    ThisCar.phone_no = phone_no;
                    ThisCar.DateRented = ui->dateEdit_rentDate->date();
                    ThisCar.DateToReturn = ui->dateEdit_rentReturnDate->date();
                    ThisCar.Cost = Cost;

                    /*check if the customer has already rented a car*/
                    if(admin.hasCustomerRented(phone_no)){
                        /*display error message*/
                        QMessageBox::critical(this, "Error", "The customer is currently holding a rented car.");
                    }else{
                        Costumer x;
                        x = admin.importCostumer(phone_no, true);

                        /*if the customer is striked less than 4 times*/
                        if (x.strikes < 3){

                            /*rent the car*/
                            admin.rentCar(ThisCar);

                            /*give a message to user*/
                            QMessageBox::information(this, "Rented", "The car has been set as rented.");

                            /*display initial bill*/

                            /*clear home tab*/
                            initializeHomeTab();
                        }else{

                            /*display error message*/
                            QMessageBox::critical(this, "Error", "The customer is listed in the black list.");
                        }
                    }
                }else{
                    /*if not available, display error message*/
                    QMessageBox::critical(this, "Error", "The car with the given plate number is not available.");
                }
            }else{
                /*if customer does not exists, display error message*/
                QMessageBox::critical(this, "Error", "The customer with the given phone number does not exist in the database.");
            }
        }else{

            /*if car does not exists, display error message*/
            QMessageBox::critical(this, "Error", "The car with the given plate number does not exist.");
        }
    }
}


/**
 * @brief INCOMPLETE
 */
void MainScreen::on_pushButton_carReturn_clicked()
{
    /*if the clicked car exists*/
    if (admin.carExists(carClicked.PlateNum)){

        /*if the clicked car is rented*/
        if(!carClicked.isAvailable){
            carClicked.DateReturned = QDate::currentDate();

            /*if deadline is crossed*/
            if(carClicked.DateReturned > carClicked.DateToReturn){
                /*strike customer and return the car and give a message*/
                admin.strikeCustomer(carClicked.phone_no);
                admin.returnCar(carClicked);
                QMessageBox::information(this, "Car Returned", "The car returned late. The customer has been striked.");
            }else{
                /*return car and give message*/
                admin.returnCar(carClicked);
                QMessageBox::information(this, "Car Returned", "The car has been returned.");
            }
            /*display final bill*/

            /*clear home tab*/
            initializeHomeTab();
        }
    }
}


/**
 * @brief change the days rented in lineEdit_rentDays if the date in dateEdit_rentDate is changed
 * @param date, date in dateEdit_rentDate
 */
void MainScreen::on_dateEdit_rentDate_dateChanged(const QDate &date)
{
    /*get date in dateEdit_rentReturnDate*/
    QDate date2 = ui->dateEdit_rentReturnDate->date();

    /*set text in lineEdit_rentDays by calcultating difference in days*/
    ui->lineEdit_rentDays->setText(QString::number(Car::calculateDaysRented(date, date2)));
}


/**
 * @brief change the days rented in lineEdit_rentDays if the date in dateEdit_rentReturnDate is changed
 * @param date, date in dateEdit_rentReturnDate
 *
 * gets date from dateEdit_rentDate
 * gets DaysRented from lineEdit_rentDays
 * calculates newDaysRented from both dates in ui
 * if DaysRented and new DaysRented are not equal, changes the days in lineEdit_rentDays
 */
void MainScreen::on_dateEdit_rentReturnDate_dateChanged(const QDate &date)
{
    /*get date in dateEdit_rentDate*/
    QDate date1 = ui->dateEdit_rentDate->date();

    /*get DaysRented from lineEdit_rentDays*/
    int DaysRented = ui->lineEdit_rentDays->text().toInt();

    /*calculate newDaysRented from both dates in ui*/
    int newDaysRented = Car::calculateDaysRented(date1, date);

    /*check if DaysRented and new DaysRented are not equal*/
    if (DaysRented != newDaysRented){
        /*change the days in lineEdit_rentDays*/
        ui->lineEdit_rentDays->setText(QString::number(newDaysRented));
    }
}


/**
 * @brief if lineEdit_rentDays is changed, changes the date on dateEdit_rentReturnDate
 * @param arg1, text in lineEdit_rentDays
 */
void MainScreen::on_lineEdit_rentDays_textChanged(const QString &arg1)
{
    QDate date1 = ui->dateEdit_rentDate->date();   //date on dateEdit_rentDate
    bool isValid = true;   //true if the entered rate is valid

    /*loop to check each character of the string*/
    for(int i = 0; i < arg1.length(); i++)
    {
        /*check if the character is digit*/
        if (!arg1[i].isDigit()){
            /*if not, change isValid to false and break the loop*/
            isValid = false;
            break;
        }else{
            try {
                int x = arg1.toInt();
                if (x > 30)
                    throw (x);
            }  catch (int x) {
                isValid = false;
                break;
            }
        }
    }

    if(isValid){
        /*change date on dateEdit_rentReturnDate by adding the number if days in lineEdit_rentDays*/
        QDate date2 = date1.addDays(arg1.toInt());
        ui->dateEdit_rentReturnDate->setDate(date2);
        ui->pushButton_rent->setEnabled(true);
        ui->label_warnDaysRented->setText("");
    }else{
        ui->pushButton_rent->setEnabled(false);
        ui->label_warnDaysRented->setText("<font color = 'red'>Enter a valid date.");
    }
    showCost(carClicked);
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
    QDate DateofBirth;
    Thiscostumer.C_fname = ui->lineEdit_fnameh->text();
    Thiscostumer.C_lname = ui->lineEdit_lname->text();
    Thiscostumer.phone_no = ui->lineEdit_phone_no->text();
    Thiscostumer.lisence_no = ui->lineEdit_lisence_no->text();
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
    DateofBirth = ui->dateEdit_DateoBirth->date();
    Thiscostumer.age = (DateofBirth.daysTo(QDate::currentDate()))/365;
    if (Thiscostumer.C_fname == ""|| Thiscostumer.C_lname=="" || Thiscostumer.gender == "" || Thiscostumer.lisence_no == "" || Thiscostumer.phone_no == "" )
    {
        QMessageBox::critical(this, "Incomplete Form", "Please fill up the forms");
    }
    else
    {
        admin.exportCostumer(Thiscostumer);
        QMessageBox::information(this, "Data added", "Costumer has been added to the database.");
    }
    ui->lineEdit_fnameh->setText("");
    ui->lineEdit_lname->setText("");
    ui->lineEdit_address->setText("");
    ui->lineEdit_lisence_no->setText("");
    ui->lineEdit_phone_no->setText("");
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
}




void MainScreen::on_tableView_customer_activated(const QModelIndex &index)
{
    QString val = ui->tableView_customer->model()->data(index).toString();
    Costumer thisCostumer;
    thisCostumer = admin.importCostumer(val,true);
    ui->label_sql_fname->setText(thisCostumer.C_fname);
    ui->label_sql_lname->setText(thisCostumer.C_lname);
    ui->label_sql_age->setText(QString::number(thisCostumer.age));
    ui->label_sql_gender->setText(thisCostumer.gender);
    ui->label_sql_phone->setText(thisCostumer.phone_no);
    ui->label_sql_lisence->setText(thisCostumer.lisence_no);
    ui->label_sql_address->setText(thisCostumer.Address);
    if (thisCostumer.strikes == 0)
    {
        ui->label_sql_Strike->setText("GREEN");
    }
    else if (thisCostumer.strikes == 1)
    {
        ui->label_sql_Strike->setText("YELLOW");
    }
    else if (thisCostumer.strikes == 2)
    {
        ui->label_sql_Strike->setText("RED");
    }
    else
    {
        ui->label_sql_Strike->setText("BLACK LISTED");
    }


}


void MainScreen::on_pushButton_carDelete_clicked()
{
    if(carClicked.isAvailable){
        admin.deleteCar(carClicked);
        QMessageBox::information(this, "Delete", "The car has been deleted from the database.");
    }else{
        QMessageBox::critical(this, "Action Failed", "The car is not available at the moment. Please try again later.");
    }
    initializeHomeTab();
}


void MainScreen::on_pushButton_Filter_costumer_clicked()
{
    if (ui->comboBox_strikes->currentIndex()==0)
    {
        ui->tableView_customer->setModel(admin.filterTableCostumer(0));
    }
    else
    {
        ui->tableView_customer->setModel(admin.filterTableCostumer(1));
    }
}

