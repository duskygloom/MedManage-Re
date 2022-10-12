#pragma once

#include <QLabel>


class NotifLabel : public QLabel
{
public:
    NotifLabel(QWidget *parent);
protected:
    void setup();
    void customize();
};
