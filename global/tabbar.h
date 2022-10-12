#pragma once

#include "global/tabbutton.h"

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

    void switchFocus(TabButton *button);

protected:
    void setup();
    void customize();
    void keyPressEvent(QKeyEvent *e) override;
    void paintEvent(QPaintEvent *e) override;

private slots:
    void onHomeClick();
    void onSearchClick();
    void onStatsClick();
    void onGraphsClick();
    void onSettingsClick();
};
