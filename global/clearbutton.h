#pragma once

#include <QPushButton>


class ClearButton : public QPushButton
{
public:
    ClearButton(QWidget *parent);
protected:
    void setup();
    void customize();
};
