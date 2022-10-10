#include "styling.h"
#include "basewidget.h"

#include <QApplication>
#include <QKeySequence>


BaseWidget::BaseWidget(QWidget *parent)
    : QWidget(parent)
{
    setup();
    customize();

    // layout
    layout->addWidget(tabbar);

    // connect
    connect(quitshort, &QShortcut::activated, qApp, &QApplication::quit);
}


void BaseWidget::setup()
{
    layout = new QVBoxLayout(this);
    tabbar = new TabBar(this);
    QKeySequence keys(Qt::CTRL + Qt::Key_Q);
    quitshort = new QShortcut(keys, this);
}

void BaseWidget::customize()
{
    QStringList normal;
    normal << QString("background-color: %1").arg(bgcolor.toRGB());
    normal << QString("color: %1").arg(fgcolor.toRGB());
    setStyleSheet(toQSS("QWidget", normal));
}
