#include "styling.h"


QString toQSS(const char *widget, const QStringList &properties)
{
    QString string(widget);
    string += " { ";
    for (QString str : properties) {
        string += str;
        string += "; ";
    }
    string += "} ";
    return string;
}
