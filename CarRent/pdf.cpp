#include "pdf.h"
extern sql admin;
extern account user;
void first_receipt(Car ThisCar)
{
    Costumer ThisCostumer = admin.importCostumer(ThisCar.phone_no,true);
    QDate now = QDate::currentDate();
    QString temp = now.toString();
    QString DateRented = ThisCar.DateRented.toString() ;
    QString DateToReturn = ThisCar.DateToReturn.toString();

    qDebug() << temp;
    QString html =
    "<div align=left>"
        "Rent-a-Car"
    "</div>"
    "<div align=right>"
       ""+temp+""
    "</div>"
    "<h1 align=center>Rent Receipt</h1>"
    "<div align=left>"
       "Received from: "+ThisCostumer.C_fname+" "+ThisCostumer.C_lname+"<br>"
       "Address: "+ThisCostumer.Address+"<br>"
       "Phone number: "+ThisCostumer.phone_no+""
    "</div>"
    "<p align=justify>"
       "The sum of "+QString::number(ThisCar.Cost)+" is paid in advance to rent '"+ThisCar.Brand+"' of model '"+ThisCar.Model+"' (Plate number: "+ThisCar.PlateNum+"), from "+DateRented+" to "+DateToReturn+".<br><br>"
       "Any late return will duely fined, and early returns will get due amount moneyback."
       "<br>"
    "</p>"
    "<div align=left>Verified by: "+user.username+"</div>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A6);
    printer.setOutputFileName("C:/pdf/"+temp+".pdf");
    printer.setPageMargins(QMarginsF(1, 1, 1, 1));

    document.print(&printer);
}


void final_receipt(Car ThisCar)
{
    Costumer ThisCostumer = admin.importCostumer(ThisCar.phone_no,true);
    QDate now = QDate::currentDate();
    QString temp = now.toString();
    QString DateRented = ThisCar.DateRented.toString() ;
    QString DateToReturn = ThisCar.DateToReturn.toString();

    qDebug() << temp;
    QString html =
    "<div align=left>"
        "Rent-a-Car"
    "</div>"
    "<div align=right>"
       ""+temp+""
    "</div>"
    "<h1 align=center>Final Receipt</h1>"
    "<div align=left>"
       "Received from: "+ThisCostumer.C_fname+" "+ThisCostumer.C_lname+"<br>"
       "Address: "+ThisCostumer.Address+"<br>"
       "Phone number: "+ThisCostumer.phone_no+""
    "</div>"
    "<p align=justify>"
       "With the advance sum of "+QString::number(ThisCar.Cost)+", '"+ThisCar.Brand+"' of model '"+ThisCar.Model+"' (Plate number: "+ThisCar.PlateNum+"), was rented from "+DateRented+" to "+DateToReturn+".<br><br>"
       "The final cost comes down to: "+QString::number(ThisCar.final_Cost)+""
       "<br>"
    "</p>"
    "<div align=left>Verified by: "+user.username+"</div>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A6);
    printer.setOutputFileName("C:/pdf/final.pdf");
    printer.setPageMargins(QMarginsF(1, 1, 1, 1));

    document.print(&printer);

}
