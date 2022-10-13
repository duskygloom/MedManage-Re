#pragma once

#include <QLabel>


class NotifLabel : public QLabel
{
public:
    NotifLabel(QFrame *parent);
protected:
    void customize();
};
