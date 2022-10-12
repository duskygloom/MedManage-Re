#include "global/tabbar.h"

#include <QDebug>
#include <QStyle>
#include <QPainter>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QStyleOption>

extern int FONTSIZE;


TabBar::TabBar(QWidget *parent)
    : QWidget(parent)
{
    setup();
    customize();

    layout->addWidget(homeButton);
    layout->addWidget(searchButton);
    layout->addWidget(statsButton);
    layout->addWidget(graphsButton);
    layout->addSpacerItem(spacer);
    layout->addWidget(settingsButton);
    tabs.append(homeButton);
    tabs.append(searchButton);
    tabs.append(statsButton);
    tabs.append(graphsButton);
    tabs.append(settingsButton);

    connect(homeButton, &QPushButton::clicked, this, &TabBar::onHomeClick);
    connect(searchButton, &QPushButton::clicked, this, &TabBar::onSearchClick);
    connect(statsButton, &QPushButton::clicked, this, &TabBar::onStatsClick);
    connect(graphsButton, &QPushButton::clicked, this, &TabBar::onGraphsClick);
    connect(settingsButton, &QPushButton::clicked, this, &TabBar::onSettingsClick);
}

void TabBar::switchFocus(TabButton *button)
{
    for (TabButton *i : tabs) {
        if (i == button) {
            i->hasFocus();
            qDebug("focused");
        }
        else {
            i->clearFocus();
            qDebug("unfocused");
        }
    }
}

void TabBar::onHomeClick()
{
    switchFocus(homeButton);
}

void TabBar::onSearchClick()
{
    switchFocus(searchButton);
}

void TabBar::onStatsClick()
{
    switchFocus(statsButton);
}

void TabBar::onGraphsClick()
{
    switchFocus(graphsButton);
}

void TabBar::onSettingsClick()
{
    switchFocus(settingsButton);
}


void TabBar::setup()
{
    setObjectName("TabBar");
    layout = new QHBoxLayout(this);
    homeButton = new TabButton(this, "Home");
    searchButton = new TabButton(this, "Search");
    statsButton = new TabButton(this, "Stats");
    graphsButton = new TabButton(this, "Graphs");
    spacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Fixed);
    settingsButton = new TabButton(this, "Settings");
}

void TabBar::customize()
{
    setFixedHeight(FONTSIZE+16);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layout->setContentsMargins(4, 4, 4, 4);
}

void TabBar::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Tab) {
        int len = tabs.length();
        for (int i=0; i<len; i+=1) {
            if (tabs[i]->hasFocus()) {
                if (i == len-1) i = -1;
                tabs[i+1]->animateClick();
                break;
}   }   }   }

void TabBar::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QStyleOption option;
    option.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}
