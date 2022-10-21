#include "homewidget.h"


HomeWidget::HomeWidget(QWidget *parent)
    : QWidget(parent)
{
    setup();
    customize();
    // connect
    connect(transtab->buyTabButton, &QPushButton::clicked, this, &HomeWidget::onBuyClick);
    connect(transtab->sellTabButton, &QPushButton::clicked, this, &HomeWidget::onSellClick);
}

void HomeWidget::onBuyClick()
{
    transtab->sellTabButton->setChecked(false);
    transtab->buyTabButton->setChecked(true);
    for (auto i : sellwidgets) i->hide();
    for (auto i : buywidgets) i->show();
}

void HomeWidget::onSellClick()
{
    transtab->buyTabButton->setChecked(false);
    transtab->sellTabButton->setChecked(true);
    for (auto i : buywidgets) i->hide();
    for (auto i : sellwidgets) i->show();
}


void HomeWidget::setup()
{
    layout = new QVBoxLayout(this);
    transtab = new TransTab(this);
    spacer = new QSpacerItem(1, 1, QSizePolicy::Fixed, QSizePolicy::Expanding);
    buybatch = new EntryLine(this);
    buyname = new EntryLine(this);
    buyqty = new EntryLine(this);
    buycost = new EntryLine(this);
    producer = new EntryLine(this);
    sellbatch = new EntryLine(this);
    sellname = new EntryLine(this);
    sellqty = new EntryLine(this);
    sellcost = new EntryLine(this);
    consumer = new EntryLine(this);
    mfg = new EntryDate(this);
    exp = new EntryDate(this);
    buydate = new EntryDate(this);
    selldate = new EntryDate(this);
    buywidgets.append(buybatch);
    buywidgets.append(buyname);
    buywidgets.append(buyqty);
    buywidgets.append(buycost);
    buywidgets.append(producer);
    buywidgets.append(mfg);
    buywidgets.append(exp);
    buywidgets.append(buydate);
    sellwidgets.append(sellbatch);
    sellwidgets.append(sellname);
    sellwidgets.append(sellqty);
    sellwidgets.append(sellcost);
    sellwidgets.append(consumer);
    sellwidgets.append(selldate);
    layout->addWidget(transtab);
    layout->addSpacerItem(spacer);
    for (auto i : buywidgets) {
        layout->addWidget(i);
        i->show();
    }
    for (auto i : sellwidgets) {
        layout->addWidget(i);
    }
}


void HomeWidget::customize()
{
    focusNextPrevChild(false);
    buybatch->setLabel("Batch number");
    sellbatch->setLabel("Batch number");
    buyname->setLabel("Medicine name");
    sellname->setLabel("Medicine name");
    buyqty->setLabel("Quantity");
    sellqty->setLabel("Quantity");
    buycost->setLabel("Cost");
    sellcost->setLabel("Cost");
    producer->setLabel("Producer");
    consumer->setLabel("Consumer");
    mfg->setLabel("Manufactured on");
    exp->setLabel("Expires on");
    buydate->setLabel("Purchased on");
    selldate->setLabel("Sold on");
}
