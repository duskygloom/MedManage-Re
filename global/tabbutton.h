#pragma once

#include <QPushButton>


class TabButton : public QPushButton
{
public:
    TabButton(QWidget *parent, const QString &text);
protected:
    void setup();
    void customize();
};
