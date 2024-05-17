/****************************************************************************
** Meta object code from reading C++ file 'GameArea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../untitled5/GameArea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameArea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameArea_t {
    QByteArrayData data[13];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameArea_t qt_meta_stringdata_GameArea = {
    {
QT_MOC_LITERAL(0, 0, 8), // "GameArea"
QT_MOC_LITERAL(1, 9, 17), // "sigUpdateNextItem"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "ItemType"
QT_MOC_LITERAL(4, 37, 4), // "type"
QT_MOC_LITERAL(5, 42, 13), // "ItemDirection"
QT_MOC_LITERAL(6, 56, 9), // "direction"
QT_MOC_LITERAL(7, 66, 14), // "sigUpdateScore"
QT_MOC_LITERAL(8, 81, 6), // "nScore"
QT_MOC_LITERAL(9, 88, 14), // "sigUpdateLevel"
QT_MOC_LITERAL(10, 103, 6), // "nSpeed"
QT_MOC_LITERAL(11, 110, 8), // "sigPause"
QT_MOC_LITERAL(12, 119, 7) // "bPaused"

    },
    "GameArea\0sigUpdateNextItem\0\0ItemType\0"
    "type\0ItemDirection\0direction\0"
    "sigUpdateScore\0nScore\0sigUpdateLevel\0"
    "nSpeed\0sigPause\0bPaused"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameArea[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       7,    1,   39,    2, 0x06 /* Public */,
       9,    1,   42,    2, 0x06 /* Public */,
      11,    1,   45,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,   12,

       0        // eod
};

void GameArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateNextItem((*reinterpret_cast< ItemType(*)>(_a[1])),(*reinterpret_cast< ItemDirection(*)>(_a[2]))); break;
        case 1: _t->sigUpdateScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sigUpdateLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sigPause((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameArea::*)(ItemType , ItemDirection );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::sigUpdateNextItem)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameArea::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::sigUpdateScore)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameArea::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::sigUpdateLevel)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GameArea::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GameArea::sigPause)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GameArea::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GameArea.data,
    qt_meta_data_GameArea,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameArea.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GameArea::sigUpdateNextItem(ItemType _t1, ItemDirection _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameArea::sigUpdateScore(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameArea::sigUpdateLevel(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameArea::sigPause(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
