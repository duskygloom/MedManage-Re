#pragma once

#include "tabbutton.h"

#include <QList>
#include <QKeyEvent>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpacerItem>


class TabBar : public QWidget
{
    Q_OBJECT

public:
    TabBar(QWidget *parent);

private:
    QHBoxLayout *layout;
    TabButton *homeButton;
    TabButton *searchButton;
    TabButton *statsButton;
    TabButton *graphsButton;
    QSpacerItem *spacer;
    TabButton *settingsButton;
    QList<TabButton*> tabs;

protected:
    void setup();
    void customize();

private slots:
    void onKeyPress(QKeyEvent *e);
    void paintEvent(QPaintEvent *e);
};
