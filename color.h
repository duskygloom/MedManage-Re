#pragma once

#include <QColor>


class Color
{
    int r, g, b, a;

public:
    explicit Color(const Color &color);
    explicit Color(const QColor &qcolor);
    explicit Color(const char *hex);
    explicit Color(int red, int green, int blue, int alpha=255);

    QString toRGB();
    QString toRGBA(int opacity=100);
    QString toHex();
    QColor toQColor();
};
