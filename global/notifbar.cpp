#include "global/notifbar.h"

#include <QStyle>
#include <QStyleOption>

extern int FONTSIZE;


NotifBar::NotifBar(QWidget *parent)
    : QWidget(parent)
{
    setup();
    customize();
    // layout
    layout->addWidget(timelabel);
    layout->addWidget(notiflabel);
    layout->addWidget(clearbutton);
    // connect
    connect(clearbutton, &QPushButton::clicked, this, &NotifBar::clear);
    // startup
    notify("MedManage started.");
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
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layout->setContentsMargins(0, 0, 0, 0);
}

void NotifBar::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QStyleOption option;
    option.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}

void NotifBar::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        clear();
}
