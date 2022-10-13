#include "global/timelabel.h"

#include <QTime>

extern int FONTSIZE;


TimeLabel::TimeLabel(QFrame *parent)
    : QLabel(parent)
{
    customize();
}

void TimeLabel::showTime()
{
    auto now = QTime::currentTime();
    auto timetext = now.toString("hh:mm");
    setText(timetext);
}


void TimeLabel::customize()
{
    setObjectName("TimeLabel");
    setFixedSize(FONTSIZE*6, FONTSIZE+8);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
