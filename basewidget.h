#pragma once

#include "global/tabbar.h"
#include "global/notifbar.h"
#include "home/homewidget.h"

#include <QWidget>
#include <QShortcut>


class BaseWidget : public QWidget
{
    Q_OBJECT

public:
    BaseWidget(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    TabBar *tabbar;
    QShortcut *quitshort;
    NotifBar *notifbar;
    HomeWidget *homewidget;
    QList<QPushButton*> toFocus;

protected:
    void setup();
    void customize();
    void keyPressEvent(QKeyEvent *e) override;
};
