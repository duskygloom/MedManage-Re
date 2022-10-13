#include "global/notifbar.h"

#include <QStyle>
#include <QStyleOption>

extern int FONTSIZE;


NotifBar::NotifBar(QWidget *parent)
    : QFrame(parent)
{
    setup();
    customize();
    // layout
    layout->addWidget(timelabel);
    layout->addWidget(notiflabel);
    layout->addWidget(clearbutton);
    // connect
    connect(clearbutton, &QPushButton::clicked, this, &NotifBar::clear);
}

void NotifBar::notify(const QString &message)
{
    timelabel->showTime();
    notiflabel->setText(message);
}

void NotifBar::clear()
{
    timelabel->setText("");
    notiflabel->setText("");
}


void NotifBar::setup()
{
    layout = new QHBoxLayout(this);
    timelabel = new TimeLabel(this);
    notiflabel = new NotifLabel(this);
    clearbutton = new ClearButton(this);
}

void NotifBar::customize()
{
    setFixedHeight(FONTSIZE+12);
    setFocusPolicy(Qt::NoFocus);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layout->setContentsMargins(0, 0, 0, 0);
}

void NotifBar::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        clear();
}
