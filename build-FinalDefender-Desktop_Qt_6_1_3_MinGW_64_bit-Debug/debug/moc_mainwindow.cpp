/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../FinalDefender/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 6), // "Level1"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 9), // "MovBasura"
QT_MOC_LITERAL(29, 6), // "Level2"
QT_MOC_LITERAL(36, 13), // "MovMeteoritos"
QT_MOC_LITERAL(50, 10), // "MovCometas"
QT_MOC_LITERAL(61, 11), // "MovMiniBoss"
QT_MOC_LITERAL(73, 7), // "MovBoss"
QT_MOC_LITERAL(81, 10), // "MovDisparo"
QT_MOC_LITERAL(92, 8), // "DanoBoss"
QT_MOC_LITERAL(101, 8), // "MovLaser"
QT_MOC_LITERAL(110, 12), // "CambioEscena"
QT_MOC_LITERAL(123, 14), // "limpiarEscena2"
QT_MOC_LITERAL(138, 14), // "limpiarEscena3"
QT_MOC_LITERAL(153, 8), // "GameOver"
QT_MOC_LITERAL(162, 10), // "PasarTurno"
QT_MOC_LITERAL(173, 13), // "GameOverMulti"
QT_MOC_LITERAL(187, 8) // "conector"

    },
    "MainWindow\0Level1\0\0MovBasura\0Level2\0"
    "MovMeteoritos\0MovCometas\0MovMiniBoss\0"
    "MovBoss\0MovDisparo\0DanoBoss\0MovLaser\0"
    "CambioEscena\0limpiarEscena2\0limpiarEscena3\0"
    "GameOver\0PasarTurno\0GameOverMulti\0"
    "conector"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x0a,    0 /* Public */,
       3,    0,  117,    2, 0x0a,    1 /* Public */,
       4,    1,  118,    2, 0x0a,    2 /* Public */,
       5,    0,  121,    2, 0x0a,    4 /* Public */,
       6,    0,  122,    2, 0x0a,    5 /* Public */,
       7,    0,  123,    2, 0x0a,    6 /* Public */,
       8,    0,  124,    2, 0x0a,    7 /* Public */,
       9,    0,  125,    2, 0x0a,    8 /* Public */,
      10,    0,  126,    2, 0x0a,    9 /* Public */,
      11,    0,  127,    2, 0x0a,   10 /* Public */,
      12,    0,  128,    2, 0x0a,   11 /* Public */,
      13,    0,  129,    2, 0x0a,   12 /* Public */,
      14,    0,  130,    2, 0x0a,   13 /* Public */,
      15,    0,  131,    2, 0x0a,   14 /* Public */,
      16,    0,  132,    2, 0x0a,   15 /* Public */,
      17,    0,  133,    2, 0x0a,   16 /* Public */,
      18,    0,  134,    2, 0x0a,   17 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Level1(); break;
        case 1: _t->MovBasura(); break;
        case 2: _t->Level2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->MovMeteoritos(); break;
        case 4: _t->MovCometas(); break;
        case 5: _t->MovMiniBoss(); break;
        case 6: _t->MovBoss(); break;
        case 7: _t->MovDisparo(); break;
        case 8: _t->DanoBoss(); break;
        case 9: _t->MovLaser(); break;
        case 10: _t->CambioEscena(); break;
        case 11: _t->limpiarEscena2(); break;
        case 12: _t->limpiarEscena3(); break;
        case 13: _t->GameOver(); break;
        case 14: _t->PasarTurno(); break;
        case 15: _t->GameOverMulti(); break;
        case 16: _t->conector(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
