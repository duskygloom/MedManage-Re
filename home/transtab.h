#pragma once

#include "home/transtabbutton.h"

#include <QHBoxLayout>
#include <QPushButton>


class TransTab : public QWidget
{
public:
    explicit TransTab(QWidget *parent = nullptr);

private:
    QHBoxLayout *layout;

public:
    TransTabButton *buyTabButton, *sellTabButton;

protected:
    void setup();
    void customize();
};
