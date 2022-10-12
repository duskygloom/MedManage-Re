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

void BaseWidget::customize() {}
