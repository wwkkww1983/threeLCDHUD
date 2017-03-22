/****************************************************************************
** Meta object code from reading C++ file 'ServerStream.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/include/ServerStream.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerStream.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ServerStream_t {
    QByteArrayData data[51];
    char stringdata0[809];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerStream_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerStream_t qt_meta_stringdata_ServerStream = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ServerStream"
QT_MOC_LITERAL(1, 13, 16), // "callQmlRefeshImg"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 25), // "callQmlRefeshImgSmallTurn"
QT_MOC_LITERAL(4, 57, 28), // "callQmlRefeshImgSmallChannel"
QT_MOC_LITERAL(5, 86, 26), // "callQmlRefeshImgSmallCross"
QT_MOC_LITERAL(6, 113, 27), // "callQmlRefeshImgSmallCamera"
QT_MOC_LITERAL(7, 141, 25), // "callQmlRefeshImgSmallLogo"
QT_MOC_LITERAL(8, 167, 26), // "callQmlRefeshImgSmallOther"
QT_MOC_LITERAL(9, 194, 14), // "strTurnChanged"
QT_MOC_LITERAL(10, 209, 15), // "strVoiceChanged"
QT_MOC_LITERAL(11, 225, 12), // "speedChanged"
QT_MOC_LITERAL(12, 238, 11), // "dialChanged"
QT_MOC_LITERAL(13, 250, 19), // "distanceTurnChanged"
QT_MOC_LITERAL(14, 270, 15), // "roadTurnChanged"
QT_MOC_LITERAL(15, 286, 18), // "distancDestChanged"
QT_MOC_LITERAL(16, 305, 15), // "timeDestChanged"
QT_MOC_LITERAL(17, 321, 17), // "limitSpeedChanged"
QT_MOC_LITERAL(18, 339, 14), // "getSocketImage"
QT_MOC_LITERAL(19, 354, 16), // "getSimpleInfoPic"
QT_MOC_LITERAL(20, 371, 17), // "getSimpleInfoWord"
QT_MOC_LITERAL(21, 389, 14), // "proEstablished"
QT_MOC_LITERAL(22, 404, 17), // "proConnectRequest"
QT_MOC_LITERAL(23, 422, 20), // "proConnectRequestCTL"
QT_MOC_LITERAL(24, 443, 22), // "proConnectRequestSmall"
QT_MOC_LITERAL(25, 466, 18), // "broadcastLocalInfo"
QT_MOC_LITERAL(26, 485, 11), // "emitRefresh"
QT_MOC_LITERAL(27, 497, 20), // "emitRefreshSmallTurn"
QT_MOC_LITERAL(28, 518, 23), // "emitRefreshSmallChannel"
QT_MOC_LITERAL(29, 542, 21), // "emitRefreshSmallCross"
QT_MOC_LITERAL(30, 564, 22), // "emitRefreshSmallCamera"
QT_MOC_LITERAL(31, 587, 20), // "emitRefreshSmallLogo"
QT_MOC_LITERAL(32, 608, 21), // "emitRefreshSmallOther"
QT_MOC_LITERAL(33, 630, 12), // "sendCtrlInfo"
QT_MOC_LITERAL(34, 643, 12), // "ctrlInfoType"
QT_MOC_LITERAL(35, 656, 4), // "type"
QT_MOC_LITERAL(36, 661, 11), // "const char*"
QT_MOC_LITERAL(37, 673, 4), // "data"
QT_MOC_LITERAL(38, 678, 11), // "setCtrlInfo"
QT_MOC_LITERAL(39, 690, 15), // "proDisconnected"
QT_MOC_LITERAL(40, 706, 7), // "strTurn"
QT_MOC_LITERAL(41, 714, 8), // "strVoice"
QT_MOC_LITERAL(42, 723, 5), // "speed"
QT_MOC_LITERAL(43, 729, 4), // "dial"
QT_MOC_LITERAL(44, 734, 12), // "distanceTurn"
QT_MOC_LITERAL(45, 747, 8), // "roadTurn"
QT_MOC_LITERAL(46, 756, 11), // "distancDest"
QT_MOC_LITERAL(47, 768, 8), // "timeDest"
QT_MOC_LITERAL(48, 777, 10), // "limitSpeed"
QT_MOC_LITERAL(49, 788, 9), // "DAY_NIGHT"
QT_MOC_LITERAL(50, 798, 10) // "RESOLUTION"

    },
    "ServerStream\0callQmlRefeshImg\0\0"
    "callQmlRefeshImgSmallTurn\0"
    "callQmlRefeshImgSmallChannel\0"
    "callQmlRefeshImgSmallCross\0"
    "callQmlRefeshImgSmallCamera\0"
    "callQmlRefeshImgSmallLogo\0"
    "callQmlRefeshImgSmallOther\0strTurnChanged\0"
    "strVoiceChanged\0speedChanged\0dialChanged\0"
    "distanceTurnChanged\0roadTurnChanged\0"
    "distancDestChanged\0timeDestChanged\0"
    "limitSpeedChanged\0getSocketImage\0"
    "getSimpleInfoPic\0getSimpleInfoWord\0"
    "proEstablished\0proConnectRequest\0"
    "proConnectRequestCTL\0proConnectRequestSmall\0"
    "broadcastLocalInfo\0emitRefresh\0"
    "emitRefreshSmallTurn\0emitRefreshSmallChannel\0"
    "emitRefreshSmallCross\0emitRefreshSmallCamera\0"
    "emitRefreshSmallLogo\0emitRefreshSmallOther\0"
    "sendCtrlInfo\0ctrlInfoType\0type\0"
    "const char*\0data\0setCtrlInfo\0"
    "proDisconnected\0strTurn\0strVoice\0speed\0"
    "dial\0distanceTurn\0roadTurn\0distancDest\0"
    "timeDest\0limitSpeed\0DAY_NIGHT\0RESOLUTION"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerStream[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       9,  222, // properties
       1,  258, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  184,    2, 0x06 /* Public */,
       3,    0,  185,    2, 0x06 /* Public */,
       4,    0,  186,    2, 0x06 /* Public */,
       5,    0,  187,    2, 0x06 /* Public */,
       6,    0,  188,    2, 0x06 /* Public */,
       7,    0,  189,    2, 0x06 /* Public */,
       8,    0,  190,    2, 0x06 /* Public */,
       9,    0,  191,    2, 0x06 /* Public */,
      10,    0,  192,    2, 0x06 /* Public */,
      11,    0,  193,    2, 0x06 /* Public */,
      12,    0,  194,    2, 0x06 /* Public */,
      13,    0,  195,    2, 0x06 /* Public */,
      14,    0,  196,    2, 0x06 /* Public */,
      15,    0,  197,    2, 0x06 /* Public */,
      16,    0,  198,    2, 0x06 /* Public */,
      17,    0,  199,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  200,    2, 0x0a /* Public */,
      19,    0,  201,    2, 0x0a /* Public */,
      20,    0,  202,    2, 0x0a /* Public */,
      21,    0,  203,    2, 0x0a /* Public */,
      22,    0,  204,    2, 0x0a /* Public */,
      23,    0,  205,    2, 0x0a /* Public */,
      24,    0,  206,    2, 0x0a /* Public */,
      25,    0,  207,    2, 0x0a /* Public */,
      26,    0,  208,    2, 0x0a /* Public */,
      27,    0,  209,    2, 0x0a /* Public */,
      28,    0,  210,    2, 0x0a /* Public */,
      29,    0,  211,    2, 0x0a /* Public */,
      30,    0,  212,    2, 0x0a /* Public */,
      31,    0,  213,    2, 0x0a /* Public */,
      32,    0,  214,    2, 0x0a /* Public */,
      33,    2,  215,    2, 0x0a /* Public */,
      38,    0,  220,    2, 0x0a /* Public */,
      39,    0,  221,    2, 0x0a /* Public */,

 // signals: parameters
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
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34, 0x80000000 | 36,   35,   37,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      40, QMetaType::QString, 0x00495003,
      41, QMetaType::QString, 0x00495003,
      42, QMetaType::Int, 0x00495003,
      43, QMetaType::Int, 0x00495003,
      44, QMetaType::QString, 0x00495003,
      45, QMetaType::QString, 0x00495003,
      46, QMetaType::QString, 0x00495003,
      47, QMetaType::QString, 0x00495003,
      48, QMetaType::Int, 0x00495003,

 // properties: notify_signal_id
       7,
       8,
       9,
      10,
      11,
      12,
      13,
      14,
      15,

 // enums: name, flags, count, data
      34, 0x0,    2,  262,

 // enum data: key, value
      49, uint(ServerStream::DAY_NIGHT),
      50, uint(ServerStream::RESOLUTION),

       0        // eod
};

void ServerStream::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerStream *_t = static_cast<ServerStream *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->callQmlRefeshImg(); break;
        case 1: _t->callQmlRefeshImgSmallTurn(); break;
        case 2: _t->callQmlRefeshImgSmallChannel(); break;
        case 3: _t->callQmlRefeshImgSmallCross(); break;
        case 4: _t->callQmlRefeshImgSmallCamera(); break;
        case 5: _t->callQmlRefeshImgSmallLogo(); break;
        case 6: _t->callQmlRefeshImgSmallOther(); break;
        case 7: _t->strTurnChanged(); break;
        case 8: _t->strVoiceChanged(); break;
        case 9: _t->speedChanged(); break;
        case 10: _t->dialChanged(); break;
        case 11: _t->distanceTurnChanged(); break;
        case 12: _t->roadTurnChanged(); break;
        case 13: _t->distancDestChanged(); break;
        case 14: _t->timeDestChanged(); break;
        case 15: _t->limitSpeedChanged(); break;
        case 16: _t->getSocketImage(); break;
        case 17: _t->getSimpleInfoPic(); break;
        case 18: _t->getSimpleInfoWord(); break;
        case 19: _t->proEstablished(); break;
        case 20: _t->proConnectRequest(); break;
        case 21: _t->proConnectRequestCTL(); break;
        case 22: _t->proConnectRequestSmall(); break;
        case 23: _t->broadcastLocalInfo(); break;
        case 24: _t->emitRefresh(); break;
        case 25: _t->emitRefreshSmallTurn(); break;
        case 26: _t->emitRefreshSmallChannel(); break;
        case 27: _t->emitRefreshSmallCross(); break;
        case 28: _t->emitRefreshSmallCamera(); break;
        case 29: _t->emitRefreshSmallLogo(); break;
        case 30: _t->emitRefreshSmallOther(); break;
        case 31: _t->sendCtrlInfo((*reinterpret_cast< ctrlInfoType(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2]))); break;
        case 32: _t->setCtrlInfo(); break;
        case 33: _t->proDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::callQmlRefeshImg)) {
                *result = 0;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::callQmlRefeshImgSmallTurn)) {
                *result = 1;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::callQmlRefeshImgSmallChannel)) {
                *result = 2;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::callQmlRefeshImgSmallCross)) {
                *result = 3;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::callQmlRefeshImgSmallCamera)) {
                *result = 4;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::callQmlRefeshImgSmallLogo)) {
                *result = 5;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::callQmlRefeshImgSmallOther)) {
                *result = 6;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::strTurnChanged)) {
                *result = 7;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::strVoiceChanged)) {
                *result = 8;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::speedChanged)) {
                *result = 9;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::dialChanged)) {
                *result = 10;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::distanceTurnChanged)) {
                *result = 11;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::roadTurnChanged)) {
                *result = 12;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::distancDestChanged)) {
                *result = 13;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::timeDestChanged)) {
                *result = 14;
            }
        }
        {
            typedef void (ServerStream::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerStream::limitSpeedChanged)) {
                *result = 15;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ServerStream *_t = static_cast<ServerStream *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->m_strTurn; break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->m_strVoice; break;
        case 2: *reinterpret_cast< int*>(_v) = _t->m_speed; break;
        case 3: *reinterpret_cast< int*>(_v) = _t->m_dial; break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->m_distanceTurn; break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->m_roadTurn; break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->m_distancDest; break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->m_timeDest; break;
        case 8: *reinterpret_cast< int*>(_v) = _t->m_limitSpeed; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ServerStream *_t = static_cast<ServerStream *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->m_strTurn != *reinterpret_cast< QString*>(_v)) {
                _t->m_strTurn = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->strTurnChanged();
            }
            break;
        case 1:
            if (_t->m_strVoice != *reinterpret_cast< QString*>(_v)) {
                _t->m_strVoice = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->strVoiceChanged();
            }
            break;
        case 2:
            if (_t->m_speed != *reinterpret_cast< int*>(_v)) {
                _t->m_speed = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->speedChanged();
            }
            break;
        case 3:
            if (_t->m_dial != *reinterpret_cast< int*>(_v)) {
                _t->m_dial = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->dialChanged();
            }
            break;
        case 4:
            if (_t->m_distanceTurn != *reinterpret_cast< QString*>(_v)) {
                _t->m_distanceTurn = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->distanceTurnChanged();
            }
            break;
        case 5:
            if (_t->m_roadTurn != *reinterpret_cast< QString*>(_v)) {
                _t->m_roadTurn = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->roadTurnChanged();
            }
            break;
        case 6:
            if (_t->m_distancDest != *reinterpret_cast< QString*>(_v)) {
                _t->m_distancDest = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->distancDestChanged();
            }
            break;
        case 7:
            if (_t->m_timeDest != *reinterpret_cast< QString*>(_v)) {
                _t->m_timeDest = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->timeDestChanged();
            }
            break;
        case 8:
            if (_t->m_limitSpeed != *reinterpret_cast< int*>(_v)) {
                _t->m_limitSpeed = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->limitSpeedChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ServerStream::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ServerStream.data,
      qt_meta_data_ServerStream,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ServerStream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerStream::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ServerStream.stringdata0))
        return static_cast<void*>(const_cast< ServerStream*>(this));
    return QWidget::qt_metacast(_clname);
}

int ServerStream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 34)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 34;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 34)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 34;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ServerStream::callQmlRefeshImg()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ServerStream::callQmlRefeshImgSmallTurn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ServerStream::callQmlRefeshImgSmallChannel()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ServerStream::callQmlRefeshImgSmallCross()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ServerStream::callQmlRefeshImgSmallCamera()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void ServerStream::callQmlRefeshImgSmallLogo()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void ServerStream::callQmlRefeshImgSmallOther()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void ServerStream::strTurnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void ServerStream::strVoiceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void ServerStream::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void ServerStream::dialChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void ServerStream::distanceTurnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void ServerStream::roadTurnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void ServerStream::distancDestChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, Q_NULLPTR);
}

// SIGNAL 14
void ServerStream::timeDestChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}

// SIGNAL 15
void ServerStream::limitSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
