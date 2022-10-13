#pragma once

#include "global/tabbar.h"
#include "global/notifbar.h"

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

protected:
    void setup();
    void customize();
    void keyPressEvent(QKeyEvent *e) override;
};
