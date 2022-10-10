#pragma once

#include "tabbar.h"

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

protected:
    void setup();
    void customize();
};
