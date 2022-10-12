#include "global/clearbutton.h"

extern int FONTSIZE;


ClearButton::ClearButton(QWidget *parent)
    : QPushButton(parent)
{
    setup();
    customize();
}

void ClearButton::setup()
{
    setObjectName("ClearButton");
}

void ClearButton::customize()
{
    setFixedSize(FONTSIZE+12, FONTSIZE+12);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
