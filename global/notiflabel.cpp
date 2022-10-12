#include "notiflabel.h"

extern int FONTSIZE;


NotifLabel::NotifLabel(QWidget *parent)
    : QLabel(parent)
{
    setup();
    customize();
}


void NotifLabel::setup()
{
    setObjectName("NotifLabel");
}

void NotifLabel::customize()
{
    setFixedHeight(FONTSIZE+8);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
