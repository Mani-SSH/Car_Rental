#ifndef PDF_H
#define PDF_H

#include "account.h"
#include "costumer.h"
#include "mainscreen.h"
#include "sql.h"
#include <QDate>
#include <QDebug>
#include <QPdfWriter>
#include <QTextDocument>
#include <QPainter>
#include <QPrinter>
#include <QtCore>
#include <QDebug>

void first_receipt (Car ThisCar);
void final_receipt (Car ThisCar);
QString generatePdfName();

#endif // PDF_H
