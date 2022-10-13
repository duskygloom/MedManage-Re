#include "basewidget.h"

#include <QFont>
#include <QFile>
#include <QDebug>
#include <QApplication>
#include <QFontDatabase>


int FONTSIZE;

QString getSourceDir();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // getting system font
    auto sysfont = QFontDatabase::systemFont(QFontDatabase::GeneralFont);
    FONTSIZE = sysfont.pointSize();
    if (FONTSIZE == -1) FONTSIZE = sysfont.pixelSize();
    app.setFont(sysfont);

    const QString styledir(getSourceDir());
    QString script("python3 %1/styles/styling.py %2 %1");
    script = script.arg(styledir).arg(FONTSIZE);
    int ret = system(script.toStdString().c_str());
    QFile sheetfile(QString("%1/styles/stylesheet.qss").arg(styledir));
    sheetfile.open(QFile::ReadOnly);
    if (ret == 0) app.setStyleSheet(sheetfile.readAll());
    else qDebug() << "Warning: Could not load stylesheet.py. Falling back to default style.";

    BaseWidget window;
    window.show();
    return app.exec();
}


QString getSourceDir()
{
    QString fname(__FILE__);
    QString dirname = fname.left(fname.lastIndexOf('/'));
    return dirname;
}
