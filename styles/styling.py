# This Python file uses the following encoding: utf-8
# file executed like styling.py <FONTSIZE> <file dir>

import sys
from colorschemes import *
from stylingclass import *


FONTSIZE = int(sys.argv[1])


def writeQSS(sheet):
    styles = {
        "background-color": BACKGROUND.toRGB(),
        "color": FOREGROUND.toRGB(),
        "outline": "none",
    }
    addBlock("*", styles, sheet)

    styles = {
        "border": "2px solid " + ACCENT.toRGB(),
        "border-radius": (FONTSIZE+BUTTONPADDING*2) / 2,
    }
    addBlock("QWidget#TabBar", styles, sheet)

    styles = {
        "background-color": ACCENT.toRGBA(0.4),
    }
    addBlock("QPushButton#TabButton:hover", styles, sheet)
    styles = {
        "background-color": ACCENT.toRGBA(0.8),
        "color": BRIGHTCOLOR.toRGB(),
    }
    addBlock("QPushButton#TabButton:focused", styles, sheet)
    addBlock("QPushButton#TabButton:pressed", styles, sheet)
    styles = {
        "background-color": "transparent",
        "border": "none",
        "border-radius": (FONTSIZE+BUTTONPADDING) / 2,
    }
    addBlock("QPushButton#TabButton", styles, sheet)

    styles = {
        "padding": "0 2 0 2",
    }
    addBlock("QLabel#NotifLabel", styles, sheet)
    addBlock("QLabel#TimeLabel", styles, sheet)

    styles = {
        "background-color": ACCENT.toRGBA(0.8),
    }
    addBlock("QPushButton#ClearButton:hover", styles, sheet)
    styles = {
        "background-color": ACCENT.toRGBA(0.9),
    }
    addBlock("QPushButton#ClearButton:pressed", styles, sheet)
    styles = {
        "background-color": ACCENT.toRGBA(0.6),
        "border-radius": (FONTSIZE+CLEARBUTTONPADDING) / 4,
        "border-style": "none",
    }
    addBlock("QPushButton#ClearButton", styles, sheet)


def main():
    sheet = open(f"{sys.argv[2]}/stylesheet.qss", "w+")
    sheet.write("")
    writeQSS(sheet)
    sheet.close()
    return 0


if __name__ == "__main__":
    main()
