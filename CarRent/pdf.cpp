#include "pdf.h"
extern sql admin;
extern account user;

QString generatePdfName()
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QString name = QString::number(date.year());
    if(date.month() < 10){
        name = name + "0" + QString::number(date.month());
    }else{
        name = name + QString::number(date.month());
    }

    if(date.day() < 10){
        name = name + "0" + QString::number(date.day());
    }else{
        name = name + QString::number(date.day());
    }

    if(time.hour() < 10){
        name = name + "0" + QString::number(time.hour());
    }else{
        name = name + QString::number(time.hour());
    }

    if(time.minute() < 10){
        name = name + "0" + QString::number(time.minute());
    }else{
        name = name + QString::number(time.minute());
    }

    if(time.second() < 10){
        name = name + "0" + QString::number(time.second());
    }else{
        name = name + QString::number(time.second());
    }

    return name;
}


void first_receipt(Car ThisCar)
{
    Costumer ThisCostumer = admin.importCostumer(ThisCar.phone_no,true);
    QString pdfName = generatePdfName() + "_i";
    QString DateRented = ThisCar.DateRented.toString() ;
    QString DateToReturn = ThisCar.DateToReturn.toString();
    QString today = QDate::currentDate().toString();

    qDebug() << pdfName;
    QString html =
    "<div align=left>"
        "Rent-a-Car"
    "</div>"
    "<div align=right>"
       ""+today+""
    "</div>"
    "<h1 align=center>Rent Receipt</h1>"
    "<div align=left>"
       "Received from: "+ThisCostumer.C_fname+" "+ThisCostumer.C_lname+"<br>"
       "Address: "+ThisCostumer.Address+"<br>"
       "Phone number: "+ThisCostumer.phone_no+""
    "</div>"
    "<p align=justify>"
       "The sum of Rs."+QString::number(ThisCar.Cost)+" is paid in advance to rent '"+ThisCar.Brand+"' of model '"+ThisCar.Model+"' (Plate number: "+ThisCar.PlateNum+"), from "+DateRented+" to "+DateToReturn+".<br><br>"
       "Any late return will duely fined, and early returns will get due amount moneyback."
       "<br>"
    "</p>"
    "<div align=left>Verified by: "+user.username+"</div>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A6);
    printer.setOutputFileName("C:/RentaCar/pdf/"+pdfName+".pdf");
    printer.setPageMargins(QMarginsF(1, 1, 1, 1));

    document.print(&printer);
}


void final_receipt(Car ThisCar)
{
    Costumer ThisCostumer = admin.importCostumer(ThisCar.phone_no,true);
    QString temp = generatePdfName() + "_f";
    QString DateRented = ThisCar.DateRented.toString() ;
    QString DateToReturn = ThisCar.DateToReturn.toString();
    QString today = QDate::currentDate().toString();

    qDebug() << temp;
    QString html =
    "<div align=left>"
        "Rent-a-Car"
    "</div>"
    "<div align=right>"
       ""+today+""
    "</div>"
    "<h1 align=center>Final Receipt</h1>"
    "<div align=left>"
       "Received from: <b>"+ThisCostumer.C_fname+" "+ThisCostumer.C_lname+"</b><br>"
       "Address: <b>"+ThisCostumer.Address+"</b><br>"
       "Phone number: <b>"+ThisCostumer.phone_no+"</b>"
    "</div>"
    "<p align=justify>"
       "With the advance sum of <b>Rs."+QString::number(ThisCar.Cost)+"</b>, <b>'"+ThisCar.Brand+"' </b> of model <b>'"+ThisCar.Model+"' (Plate number: "+ThisCar.PlateNum+")</b>, was rented from "+DateRented+" to "+DateToReturn+".<br><br>"
       "The final cost comes down to: <b>Rs."+QString::number(ThisCar.final_Cost)+"</b>"
       "<br>"
    "</p>"
    "<div align=left>Verified by: "+user.username+"</div>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A6);
    printer.setOutputFileName("C:/RentaCar/pdf/"+temp+".pdf");
    printer.setPageMargins(QMarginsF(1, 1, 1, 1));

    document.print(&printer);

}
