#include "color.h"
#include "basewidget.h"
#include <QFont>
#include <QApplication>
#include <QFontDatabase>


int FONTSIZE;
Color bgcolor("#1f1f1f");
Color fgcolor("#03dac5");
Color accent("#bb86fc");


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyleSheet("* { outline: none; }");

    // getting system font
    auto sysfont = QFontDatabase::systemFont(QFontDatabase::GeneralFont);
    FONTSIZE = sysfont.pointSize();
    if (FONTSIZE == -1) FONTSIZE = sysfont.pixelSize();
    app.setFont(sysfont);

    BaseWidget window;
    window.show();
    return app.exec();
}
