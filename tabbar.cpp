#include "tabbar.h"

#include <QStyle>
#include <QPainter>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QStyleOption>


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
}

void TabBar::onKeyPress(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Tab) {
        int len = tabs.length();
        for (int i=0; i<len; i+=1) {
            if (tabs[i]->hasFocus()) {
                if (i == len-1) i = -1;
                tabs[i+1]->animateClick();
                break;
            }
        }
    }
}

void TabBar::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QStyleOption option;
    option.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}


void TabBar::setup()
{
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
    QStringList normal;
    normal << QString("background-color: transparent");
    normal << QString("border: 2px solid %1").arg(accent.toRGB());
    normal << QString("border-radius: %1").arg(height()/2);
    setStyleSheet(toQSS("QWidget", normal));
}
