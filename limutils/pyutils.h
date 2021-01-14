#include <Python.h>

typedef PyObject* POBJECT;

#define LIM_PLONG(_long) (PyLong_FromLong(_long));
#define LIM_PDOUBLE(_double) (PyFloat_FromDouble(_double));
#define LIM_PDOUBLE_FROM_STR(_Dstring) (PyFloat_FromString(_Dstring));
#define LIM_PSTR(_string) (PyUnicode_FromString(_string));
#define LIM_PIMPORT(_import) (PyImport_ImportModule(_import));
#define LIM_PFUNC_NOARG(_funcname) (PyObject_CallNoArgs(_funcname));
#define LIM_PFUNC_ONEARG(_funcname, _arg1) (PyObject_CallOneArg(_funcname, _arg1));
#define LIM_PFUNC_ARGS(_funcname, _tuple) (PyObject_CallObject(_funcname, _tuple));
#define LIM_PCHECK_LONG(_PLONG) (PyLong_Check(_PLONG));
#define LIM_PCHECK_DOUBLE(_PDOUBLE) (PyFloat_Check(_PDOUBLE));
#define LIM_PCHECK_STR(_PSTR) (PyUnicode_Check(_PSTR));
#define LIM_PGET_ATTR(_attr, _attr_name) (PyObject_GetAttrString(_attr, _attr_name));
#define LIM_PSET_ATTR(_attr, _attr_name, _set_val) (PyObject_SetAttrString(_attr, _attr_name, _set_val));
#define LIM_POBJECT_STR(_obj) (PyObject_Str(_obj));
#define LIM_PCHECK_TUPLE(_obj) (PyTuple_Check(_obj));
#define LIM_PMAKE_TUPLE(_count) (PyTuple_New(_count));
#define LIM_PADD_TUPLE(_obj, _index, _type) (PyTuple_SetItem(_obj, _index, _type));
#define LIM_PGET_TUPLE_ITEM(_obj, _pos) (PyTuple_GetItem(_obj, _pos));
#define LIM_PSIZE_TUPLE(_obj) (PyTuple_Size(_obj));
#define LIM_PRESIZE_TUPLE(_obj, _newsize) (_PyTuple_Resize(_obj));

namespace PC_TILL {
    const char* toString(POBJECT o);
    long toLong(POBJECT o);
    double toDouble(POBJECT o);
}

