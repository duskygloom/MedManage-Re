#include "entryline.h"

extern int FONTSIZE;


EntryLine::EntryLine(QWidget *parent)
    : QWidget(parent)
{
    setup();
    customize();

    layout->addWidget(label);
    layout->addWidget(lineedit);
}

QString EntryLine::getText()
{
    return lineedit->text();
}

void EntryLine::setText(const QString &text)
{
    lineedit->setText(text);
}

void EntryLine::setLabel(const QString &text)
{
    label->setText(text);
}


void EntryLine::setup()
{
    layout = new QHBoxLayout(this);
    label = new QLabel(this);
    lineedit = new QLineEdit(this);
}

void EntryLine::customize()
{
    label->setObjectName("EntryLabel");
    focusNextPrevChild(false);
    lineedit->setObjectName("EntryLine");
    lineedit->setFocusPolicy(Qt::ClickFocus);
    hide();
    label->setFixedSize(FONTSIZE*16, FONTSIZE+16);
    lineedit->setFixedHeight(FONTSIZE+16);
}
