/****************************************************************************
** Meta object code from reading C++ file 'changepicsmallother.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/include/changepicsmallother.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'changepicsmallother.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChangePicsSmallOther_t {
    QByteArrayData data[3];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChangePicsSmallOther_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChangePicsSmallOther_t qt_meta_stringdata_ChangePicsSmallOther = {
    {
QT_MOC_LITERAL(0, 0, 20), // "ChangePicsSmallOther"
QT_MOC_LITERAL(1, 21, 19), // "refeshImgSmallOther"
QT_MOC_LITERAL(2, 41, 0) // ""

    },
    "ChangePicsSmallOther\0refeshImgSmallOther\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChangePicsSmallOther[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void ChangePicsSmallOther::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChangePicsSmallOther *_t = static_cast<ChangePicsSmallOther *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refeshImgSmallOther(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ChangePicsSmallOther::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ChangePicsSmallOther::refeshImgSmallOther)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ChangePicsSmallOther::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ChangePicsSmallOther.data,
      qt_meta_data_ChangePicsSmallOther,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChangePicsSmallOther::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChangePicsSmallOther::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChangePicsSmallOther.stringdata0))
        return static_cast<void*>(const_cast< ChangePicsSmallOther*>(this));
    return QThread::qt_metacast(_clname);
}

int ChangePicsSmallOther::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ChangePicsSmallOther::refeshImgSmallOther()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
