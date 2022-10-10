#include "color.h"


Color::Color(const Color &color)
    : r(color.r), g(color.g), b(color.b), a(color.a) {}

Color::Color(const QColor &qcolor)
    : r(qcolor.red()), g(qcolor.green()), b(qcolor.blue()), a(qcolor.alpha()) {}

Color::Color(const char *hex)
{
    QColor qcolor(hex);
    r = qcolor.red();
    g = qcolor.green();
    b = qcolor.blue();
    a = qcolor.alpha();
}

Color::Color(int red, int green, int blue, int alpha)
    : r(red), g(green), b(blue), a(alpha) {}

QString Color::toRGB()
{
    QString string("rgb(%1, %2, %3)");
    return string.arg(r).arg(g).arg(b);
}

QString Color::toRGBA(int opacity)
{
    a = (int)(opacity * 2.55);
    QString string("rgba(%1, %2, %3, %4)");
    return string.arg(r).arg(g).arg(b).arg(a);
}

QString Color::toHex()
{
    QColor qcolor(r, g, b, a);
    return qcolor.name();
}

QColor Color::toQColor()
{
    QColor qcolor(r, g, b, a);
    return qcolor;
}
