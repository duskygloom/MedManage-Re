#include "transtabbutton.h"

extern int FONTSIZE;


TransTabButton::TransTabButton(QWidget *parent)
    : QPushButton(parent)
{
    customize();
}


void TransTabButton::customize()
{
    setObjectName("TabButton");
    setCheckable(true);
    setFocusPolicy(Qt::NoFocus);
    setFixedHeight(FONTSIZE+8);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
