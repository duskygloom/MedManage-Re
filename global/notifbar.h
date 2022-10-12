#pragma once

#include "global/timelabel.h"
#include "global/notiflabel.h"
#include "global/clearbutton.h"

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QHBoxLayout>


class NotifBar : public QWidget
{
public:
    explicit NotifBar(QWidget *parent = nullptr);
    void notify(const QString &message);
    void clear();

private:
    QHBoxLayout *layout;
    TimeLabel *timelabel;
    NotifLabel *notiflabel;
    ClearButton *clearbutton;

protected:
    void setup();
    void customize();
    void paintEvent(QPaintEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent *e) override;
};
