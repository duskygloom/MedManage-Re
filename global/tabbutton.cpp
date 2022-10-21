#include "global/tabbutton.h"

extern int FONTSIZE;


TabButton::TabButton(QFrame *parent, const QString &text)
    : QPushButton(parent)
{
    customize();
    setText(text);
}


void TabButton::customize()
{
    setObjectName("TabButton");
    setCheckable(true);
    setFocusPolicy(Qt::NoFocus);
    setFixedSize(FONTSIZE*10, FONTSIZE+8);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
