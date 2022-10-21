#pragma once

#include "home/transtab.h"
#include "home/entrydate.h"
#include "home/entryline.h"

#include <QList>
#include <QVBoxLayout>
#include <QSpacerItem>


class HomeWidget : public QWidget
{
public:
    explicit HomeWidget(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QSpacerItem *spacer;
    EntryLine *buyname, *buybatch, *buyqty, *buycost, *producer;
    EntryLine *sellname, *sellbatch, *sellqty, *sellcost, *consumer;
    EntryDate *mfg, *exp, *buydate, *selldate;
    QList<QWidget*> buywidgets, sellwidgets;

public:
    TransTab *transtab;

private slots:
    void onBuyClick();
    void onSellClick();

protected:
    void setup();
    void customize();
};
