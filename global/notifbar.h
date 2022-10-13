#pragma once

#include "global/timelabel.h"
#include "global/notiflabel.h"
#include "global/clearbutton.h"

#include <QFrame>
#include <QMouseEvent>
#include <QHBoxLayout>


class NotifBar : public QFrame
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
    void mouseDoubleClickEvent(QMouseEvent *e) override;
};
