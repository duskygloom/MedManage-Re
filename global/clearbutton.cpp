#include "global/clearbutton.h"

extern int FONTSIZE;


ClearButton::ClearButton(QFrame *parent)
    : QPushButton(parent)
{
    customize();
}


void ClearButton::customize()
{
    setObjectName("ClearButton");
    setFocusPolicy(Qt::NoFocus);
    setFixedSize(FONTSIZE+12, FONTSIZE+12);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setIconSize(QSize(FONTSIZE+6, FONTSIZE+6));
}
