#pragma once

#include <QLabel>


class TimeLabel : public QLabel
{
public:
    TimeLabel(QWidget *parent);
    void showTime();
protected:
    void setup();
    void customize();
};
