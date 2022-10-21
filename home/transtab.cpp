#include "transtab.h"

extern int FONTSIZE;


TransTab::TransTab(QWidget *parent)
    : QWidget(parent)
{
    setup();
    customize();

    layout->addWidget(buyTabButton);
    layout->addWidget(sellTabButton);
    buyTabButton->setText("Purchase");
    sellTabButton->setText("Sell");
}


void TransTab::setup()
{
    layout = new QHBoxLayout(this);
    buyTabButton = new TransTabButton(this);
    sellTabButton = new TransTabButton(this);
}

void TransTab::customize()
{
    focusNextPrevChild(false);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout->setSpacing(10);
}
