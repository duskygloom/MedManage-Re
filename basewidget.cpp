#include "basewidget.h"

#include <QSpacerItem>
#include <QApplication>
#include <QKeySequence>


BaseWidget::BaseWidget(QWidget *parent)
    : QWidget(parent)
{
    setup();
    customize();
    // layout
    layout->addWidget(tabbar);
    layout->addWidget(homewidget);
    layout->addWidget(notifbar);
    // connect
    connect(quitshort, &QShortcut::activated, qApp, &QApplication::quit);
    // startup
    notifbar->notify("MedManage started.");
    tabbar->homeButton->animateClick();
    homewidget->transtab->buyTabButton->animateClick();
}


void BaseWidget::setup()
{
    setObjectName("BaseWidget");
    layout = new QVBoxLayout(this);
    tabbar = new TabBar(this);
    QKeySequence keys(Qt::CTRL + Qt::Key_Q);
    quitshort = new QShortcut(keys, this);
    homewidget = new HomeWidget(this);
    notifbar = new NotifBar(this);
    toFocus.append(tabbar->homeButton);
    toFocus.append(tabbar->searchButton);
    toFocus.append(tabbar->statsButton);
    toFocus.append(tabbar->graphsButton);
    toFocus.append(tabbar->settingsButton);
//    toFocus.append(homewidget->transtab->buyTabButton);
//    toFocus.append(homewidget->transtab->sellTabButton);
}

void BaseWidget::customize() {
    focusNextPrevChild(false);
}

void BaseWidget::keyPressEvent(QKeyEvent *e)
{
    QList<QPushButton*> tabs;
    for (auto i : toFocus)
        if (i->isVisible()) tabs.append(i);
    if (e->key() == Qt::Key_Tab) {
        int len = tabs.length();
        for (int i=0; i<len; i+=1) {
            if (tabs[i]->isChecked()) {
                if (i == len-1) i = -1;
                tabs[i+1]->animateClick();
                break;
            }
        }
    }
}
