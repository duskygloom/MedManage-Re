#include "tabbutton.h"


TabButton::TabButton(QWidget *parent, const QString &text)
    : QPushButton(parent)
{
    customize();
    setText(text);
}


void TabButton::customize()
{
    setFixedSize(FONTSIZE*10, FONTSIZE+8);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QStringList hover;
    hover << QString("background-color: %1").arg(accent.toRGBA(40));
    QStringList focused;
    focused << QString("background-color: %1").arg(accent.toRGBA(80));
    focused << QString("color: #ffffff");
    QStringList normal;
    normal << QString("background-color: transparent");
    normal << QString("border-style: none");
    normal << QString("border-radius: %1").arg(height()/2);
    setStyleSheet(toQSS("QPushButton::hover", hover)
                  + toQSS("QPushButton::focus", focused)
                  + toQSS("QPushButton", normal));
}
