#pragma once

#include "styling.h"

#include <QPushButton>


class TabButton : public QPushButton
{
public:
    TabButton(QWidget *parent, const QString &text);
protected:
    void customize();
};
