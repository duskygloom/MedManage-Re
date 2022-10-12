#include "global/tabbutton.h"

extern int FONTSIZE;


TabButton::TabButton(QWidget *parent, const QString &text)
    : QPushButton(parent)
{
    setup();
    customize();
    setText(text);
}


void TabButton::setup()
{
    setObjectName("TabButton");
}

void TabButton::customize()
{
    setFixedSize(FONTSIZE*10, FONTSIZE+8);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
