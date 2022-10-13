#include "global/tabbar.h"

#include <QDebug>
#include <QStyle>
#include <QPainter>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QStyleOption>

extern int FONTSIZE;


TabBar::TabBar(QWidget *parent)
    : QFrame(parent)
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

void TabBar::switchTab(TabButton *button)
{
    for (TabButton *i : tabs)
        i->setChecked(false);
    button->setChecked(true);
}

void TabBar::onHomeClick()
{
    switchTab(homeButton);
}

void TabBar::onSearchClick()
{
    switchTab(searchButton);
}

void TabBar::onStatsClick()
{
    switchTab(statsButton);
}

void TabBar::onGraphsClick()
{
    switchTab(graphsButton);
}

void TabBar::onSettingsClick()
{
    switchTab(settingsButton);
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
    setFocusPolicy(Qt::NoFocus);
    setFixedHeight(FONTSIZE+16);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layout->setContentsMargins(2, 2, 2, 2);
}
