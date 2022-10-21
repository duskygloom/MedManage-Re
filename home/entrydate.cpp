#include "entrydate.h"

extern int FONTSIZE;


EntryDate::EntryDate(QWidget *parent)
    : QWidget(parent)
{
    setup();
    customize();

    layout->addWidget(label);
    layout->addWidget(dateedit);
}

QDate EntryDate::getDate()
{
    return dateedit->date();
}

void EntryDate::setDate(const QDate &date)
{
    dateedit->setDate(date);
}

void EntryDate::setLabel(const QString &text)
{
    label->setText(text);
}


void EntryDate::setup()
{
    layout = new QHBoxLayout(this);
    label = new QLabel(this);
    dateedit = new QDateEdit(this);
}

void EntryDate::customize()
{
    label->setObjectName("EntryLabel");
    dateedit->setObjectName("EntryDate");
    dateedit->setFocusPolicy(Qt::ClickFocus);
    dateedit->setDate(QDate::currentDate());
    focusNextPrevChild(false);
    hide();
    label->setFixedSize(FONTSIZE*16, FONTSIZE+10);
    dateedit->setFixedHeight(FONTSIZE+10);
}
