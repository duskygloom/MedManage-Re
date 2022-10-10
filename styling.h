#pragma once

#include "color.h"
#include <QPushButton>

extern int FONTSIZE;
extern Color bgcolor;
extern Color fgcolor;
extern Color accent;


QString toQSS(const char *widget, const QStringList &properties);
