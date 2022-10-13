#include "notiflabel.h"

extern int FONTSIZE;


NotifLabel::NotifLabel(QFrame *parent)
    : QLabel(parent)
{
    customize();
}


void NotifLabel::customize()
{
    setObjectName("NotifLabel");
    setFixedHeight(FONTSIZE+8);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}
