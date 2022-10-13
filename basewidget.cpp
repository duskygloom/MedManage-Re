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
    auto spacer = new QSpacerItem(1, 1, QSizePolicy::Fixed, QSizePolicy::Expanding);
    layout->addSpacerItem(spacer);
    layout->addWidget(notifbar);
    // connect
    connect(quitshort, &QShortcut::activated, qApp, &QApplication::quit);
    // startup
    tabbar->tabs[0]->animateClick();
    notifbar->notify("MedManage started.");
}


void BaseWidget::setup()
{
    setObjectName("BaseWidget");
    layout = new QVBoxLayout(this);
    tabbar = new TabBar(this);
    QKeySequence keys(Qt::CTRL + Qt::Key_Q);
    quitshort = new QShortcut(keys, this);
    notifbar = new NotifBar(this);
}

void BaseWidget::customize() {
    focusNextPrevChild(false);
}

void BaseWidget::keyPressEvent(QKeyEvent *e)
{
    QList<TabButton*> tabs(tabbar->tabs);
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
