#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>


class EntryLine : public QWidget
{
public:
    EntryLine(QWidget *parent);
private:
    QHBoxLayout *layout;
    QLabel *label;
    QLineEdit *lineedit;
public:
    QString getText();
    void setText(const QString &text);
    void setLabel(const QString &text);
protected:
    void setup();
    void customize();
};
