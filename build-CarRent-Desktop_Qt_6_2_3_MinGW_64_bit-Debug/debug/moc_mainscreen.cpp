/****************************************************************************
** Meta object code from reading C++ file 'mainscreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CarRent/mainscreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainScreen_t {
    const uint offsetsAndSize[26];
    char stringdata0[266];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainScreen_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainScreen_t qt_meta_stringdata_MainScreen = {
    {
QT_MOC_LITERAL(0, 10), // "MainScreen"
QT_MOC_LITERAL(11, 27), // "on_lineEdit_rate_textEdited"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 4), // "arg1"
QT_MOC_LITERAL(45, 28), // "on_pushButton_addCar_clicked"
QT_MOC_LITERAL(74, 27), // "on_tableView_Cars_activated"
QT_MOC_LITERAL(102, 11), // "QModelIndex"
QT_MOC_LITERAL(114, 5), // "index"
QT_MOC_LITERAL(120, 31), // "on_pushButton_carSearch_clicked"
QT_MOC_LITERAL(152, 31), // "on_pushButton_carReload_clicked"
QT_MOC_LITERAL(184, 31), // "on_pushButton_carFilter_clicked"
QT_MOC_LITERAL(216, 27), // "on_pushButton_admin_clicked"
QT_MOC_LITERAL(244, 21) // "on_pushButton_clicked"

    },
    "MainScreen\0on_lineEdit_rate_textEdited\0"
    "\0arg1\0on_pushButton_addCar_clicked\0"
    "on_tableView_Cars_activated\0QModelIndex\0"
    "index\0on_pushButton_carSearch_clicked\0"
    "on_pushButton_carReload_clicked\0"
    "on_pushButton_carFilter_clicked\0"
    "on_pushButton_admin_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainScreen[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x08,    1 /* Private */,
       4,    0,   65,    2, 0x08,    3 /* Private */,
       5,    1,   66,    2, 0x08,    4 /* Private */,
       8,    0,   69,    2, 0x08,    6 /* Private */,
       9,    0,   70,    2, 0x08,    7 /* Private */,
      10,    0,   71,    2, 0x08,    8 /* Private */,
      11,    0,   72,    2, 0x08,    9 /* Private */,
      12,    0,   73,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainScreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_lineEdit_rate_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_addCar_clicked(); break;
        case 2: _t->on_tableView_Cars_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_carSearch_clicked(); break;
        case 4: _t->on_pushButton_carReload_clicked(); break;
        case 5: _t->on_pushButton_carFilter_clicked(); break;
        case 6: _t->on_pushButton_admin_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainScreen.offsetsAndSize,
    qt_meta_data_MainScreen,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainScreen_t
, QtPrivate::TypeAndForceComplete<MainScreen, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainScreen.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
