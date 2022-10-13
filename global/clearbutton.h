#pragma once

#include <QFrame>
#include <QPushButton>


class ClearButton : public QPushButton
{
public:
    ClearButton(QFrame *parent);
protected:
    void customize();
};
