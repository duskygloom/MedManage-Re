#include "global/timelabel.h"

#include <QTime>

extern int FONTSIZE;


TimeLabel::TimeLabel(QWidget *parent)
    : QLabel(parent)
{
    setup();
    customize();
}

void TimeLabel::showTime()
{
    auto now = QTime::currentTime();
    auto timetext = now.toString("hh:mm");
    setText(timetext);
}

void TimeLabel::setup()
{
    setObjectName("TimeLabel");
}

void TimeLabel::customize()
{
    setFixedSize(FONTSIZE*6, FONTSIZE+8);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
