#include "pyutils.h"
#include <iostream>

using namespace std;

    const char* toString(POBJECT o) {
        bool checkString = LIM_PCHECK_STR(o);
        if (!checkString) {
            std::cout << "Invalid type conversion" << std::endl;
            return "Error!";
        }
        else {
            POBJECT temp_bytes = PyUnicode_AsEncodedString(o, "UTF-8", "strict");
            const char* result = PyBytes_AS_STRING(temp_bytes);
            Py_CLEAR(temp_bytes);
            return result;
        }
    }
    long toLong(POBJECT o) {
        bool checkLong = LIM_PCHECK_LONG(o);
        if (checkLong) {
            std::cout << "Invalid type conversion returned -1";
            return -1;
        }
        else
        {
            long result = PyLong_AsLong(o);
            return result;
        }
    }

    double toDouble(POBJECT o) {
        bool checkDouble = LIM_PCHECK_DOUBLE(o);
        if (checkDouble) {
            std::cout << "Invalid type conversion returned -1";
        }
        else {
            double result = PyFloat_AsDouble(o);
            return result;
        }
    }

PyObject* LimPY_Inits::mailServerObject = nullptr;

PyObject* LimPY_Inits::getMailServer()
{
    return mailServerObject;
}

bool LimPY_Inits::connectMailServer()
{
    PyObject* imports = PyImport_ImportModule("mailer");
    PyObject* func = PyObject_GetAttrString(imports, "connectmailserver");
    PyObject* calledOBJ = PyObject_CallNoArgs(func);

    mailServerObject = calledOBJ;
    if (PyErr_Occurred()) {

        std::cout << "Excetion occured during connection to smtp" << std::endl;
        Py_CLEAR(imports);
        Py_CLEAR(func);
        return false;
    }

    Py_CLEAR(imports);
    Py_CLEAR(func);
    return true;
}
