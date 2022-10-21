#pragma once

#include <QPushButton>


class TransTabButton : public QPushButton
{
public:
    TransTabButton(QWidget *parent);
protected:
    void customize();
};
