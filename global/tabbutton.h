#pragma once

#include <QFrame>
#include <QPushButton>


class TabButton : public QPushButton
{
public:
    TabButton(QFrame *parent, const QString &text);
protected:
    void setup();
    void customize();
};
