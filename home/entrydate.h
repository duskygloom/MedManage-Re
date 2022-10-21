#pragma once

#include <QLabel>
#include <QDateEdit>
#include <QHBoxLayout>


class EntryDate : public QWidget
{
public:
    EntryDate(QWidget *parent);
private:
    QLabel *label;
    QDateEdit *dateedit;
public:
    QHBoxLayout *layout;
    QDate getDate();
    void setDate(const QDate &date);
    void setLabel(const QString &text);
protected:
    void setup();
    void customize();
};
