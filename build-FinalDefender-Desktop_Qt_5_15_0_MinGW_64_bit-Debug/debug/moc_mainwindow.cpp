/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../FinalDefender/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "Level1"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 9), // "MovBasura"
QT_MOC_LITERAL(4, 29, 6), // "Level2"
QT_MOC_LITERAL(5, 36, 13), // "MovMeteoritos"
QT_MOC_LITERAL(6, 50, 10), // "MovCometas"
QT_MOC_LITERAL(7, 61, 11), // "MovMiniBoss"
QT_MOC_LITERAL(8, 73, 7), // "MovBoss"
QT_MOC_LITERAL(9, 81, 10), // "MovDisparo"
QT_MOC_LITERAL(10, 92, 8), // "DanoBoss"
QT_MOC_LITERAL(11, 101, 8), // "MovLaser"
QT_MOC_LITERAL(12, 110, 12), // "CambioEscena"
QT_MOC_LITERAL(13, 123, 14), // "limpiarEscena2"
QT_MOC_LITERAL(14, 138, 14), // "limpiarEscena3"
QT_MOC_LITERAL(15, 153, 8), // "GameOver"
QT_MOC_LITERAL(16, 162, 10), // "PasarTurno"
QT_MOC_LITERAL(17, 173, 13), // "GameOverMulti"
QT_MOC_LITERAL(18, 187, 8) // "conector"

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
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    1,  101,    2, 0x0a /* Public */,
       5,    0,  104,    2, 0x0a /* Public */,
       6,    0,  105,    2, 0x0a /* Public */,
       7,    0,  106,    2, 0x0a /* Public */,
       8,    0,  107,    2, 0x0a /* Public */,
       9,    0,  108,    2, 0x0a /* Public */,
      10,    0,  109,    2, 0x0a /* Public */,
      11,    0,  110,    2, 0x0a /* Public */,
      12,    0,  111,    2, 0x0a /* Public */,
      13,    0,  112,    2, 0x0a /* Public */,
      14,    0,  113,    2, 0x0a /* Public */,
      15,    0,  114,    2, 0x0a /* Public */,
      16,    0,  115,    2, 0x0a /* Public */,
      17,    0,  116,    2, 0x0a /* Public */,
      18,    0,  117,    2, 0x0a /* Public */,

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
        Q_UNUSED(_t)
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

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
