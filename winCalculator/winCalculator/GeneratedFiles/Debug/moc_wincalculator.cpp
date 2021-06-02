/****************************************************************************
** Meta object code from reading C++ file 'wincalculator.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../wincalculator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wincalculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_winCalculator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      37,   14,   14,   14, 0x08,
      57,   14,   14,   14, 0x08,
      77,   14,   14,   14, 0x08,
      97,   14,   14,   14, 0x08,
     119,   14,   14,   14, 0x08,
     140,   14,   14,   14, 0x08,
     161,   14,   14,   14, 0x08,
     181,   14,   14,   14, 0x08,
     203,   14,   14,   14, 0x08,
     225,   14,   14,   14, 0x08,
     246,   14,   14,   14, 0x08,
     267,   14,   14,   14, 0x08,
     289,   14,   14,   14, 0x08,
     311,   14,   14,   14, 0x08,
     331,   14,   14,   14, 0x08,
     351,   14,   14,   14, 0x08,
     371,   14,   14,   14, 0x08,
     393,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_winCalculator[] = {
    "winCalculator\0\0on_clearBtn_clicked()\0"
    "on_delBtn_clicked()\0on_oneBtn_clicked()\0"
    "on_twoBtn_clicked()\0on_threeBtn_clicked()\0"
    "on_fourBtn_clicked()\0on_fiveBtn_clicked()\0"
    "on_sixBtn_clicked()\0on_sevenBtn_clicked()\0"
    "on_eightBtn_clicked()\0on_nineBtn_clicked()\0"
    "on_zeroBtn_clicked()\0on_pointBtn_clicked()\0"
    "on_multiBtn_clicked()\0on_divBtn_clicked()\0"
    "on_addBtn_clicked()\0on_subBtn_clicked()\0"
    "on_equalBtn_clicked()\0on_surplusBtn_clicked()\0"
};

void winCalculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        winCalculator *_t = static_cast<winCalculator *>(_o);
        switch (_id) {
        case 0: _t->on_clearBtn_clicked(); break;
        case 1: _t->on_delBtn_clicked(); break;
        case 2: _t->on_oneBtn_clicked(); break;
        case 3: _t->on_twoBtn_clicked(); break;
        case 4: _t->on_threeBtn_clicked(); break;
        case 5: _t->on_fourBtn_clicked(); break;
        case 6: _t->on_fiveBtn_clicked(); break;
        case 7: _t->on_sixBtn_clicked(); break;
        case 8: _t->on_sevenBtn_clicked(); break;
        case 9: _t->on_eightBtn_clicked(); break;
        case 10: _t->on_nineBtn_clicked(); break;
        case 11: _t->on_zeroBtn_clicked(); break;
        case 12: _t->on_pointBtn_clicked(); break;
        case 13: _t->on_multiBtn_clicked(); break;
        case 14: _t->on_divBtn_clicked(); break;
        case 15: _t->on_addBtn_clicked(); break;
        case 16: _t->on_subBtn_clicked(); break;
        case 17: _t->on_equalBtn_clicked(); break;
        case 18: _t->on_surplusBtn_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData winCalculator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject winCalculator::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_winCalculator,
      qt_meta_data_winCalculator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &winCalculator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *winCalculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *winCalculator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_winCalculator))
        return static_cast<void*>(const_cast< winCalculator*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int winCalculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
