#pragma once

#include <QLabel>


class TimeLabel : public QLabel
{
public:
    TimeLabel(QFrame *parent);
    void showTime();
protected:
    void customize();
};
