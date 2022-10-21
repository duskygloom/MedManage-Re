#pragma once

#include "global/tabbutton.h"

#include <QList>
#include <QFrame>
#include <QKeyEvent>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpacerItem>


class TabBar : public QFrame
{
    Q_OBJECT

public:
    TabBar(QWidget *parent);
    QList<TabButton*> tabs;

private:
    QHBoxLayout *layout;
    QSpacerItem *spacer;

public:
    TabButton *homeButton;
    TabButton *searchButton;
    TabButton *statsButton;
    TabButton *graphsButton;
    TabButton *settingsButton;

private:
    void switchTab(TabButton *button);

protected:
    void setup();
    void customize();

private slots:
    void onHomeClick();
    void onSearchClick();
    void onStatsClick();
    void onGraphsClick();
    void onSettingsClick();
};
