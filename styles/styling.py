# This Python file uses the following encoding: utf-8
# file executed like styling.py FONTSIZE filedir colorscheme

import sys
from colorschemes import *
from stylingclass import *


colorscheme = "defaultdark"

def writeQSS(sheet):
    styles = {
        "background-color": BACKGROUND.toRGB(),
        "color": FOREGROUND.toRGB(),
        "outline": "none",
    }
    addBlock("*", styles, sheet)

    styles = {
        "border": "2px solid " + ACCENT.toRGB(),
        "border-radius": (FONTSIZE+SMALLPAD*2) / 2,
    }
    addBlock("QWidget#TabBar", styles, sheet)

    styles = {
        "background-color": "transparent",
        "border": "none",
        "border-radius": (FONTSIZE+SMALLPAD) / 2,
    }
    addBlock("QPushButton#TabButton", styles, sheet)
    styles = {
        "background-color": ACCENT.toRGBA(0.4),
    }
    addBlock("QPushButton#TabButton:hover", styles, sheet)
    styles = {
        "background-color": ACCENT.toRGBA(0.8),
        "color": BRIGHTTEXT.toRGB(),
    }
    addBlock("QPushButton#TabButton:checked", styles, sheet)
    styles = {
        "background-color": ACCENT.toRGB(),
        "color": BRIGHTTEXT.toRGB(),
    }
    addBlock("QPushButton#TabButton:pressed", styles, sheet)

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
        "border-radius": (FONTSIZE+LARGEPAD) / 4,
        "border-style": "none",
        "qproperty-icon": f"url({getIconURL('clear_all', BRIGHTTEXT)})",
    }
    addBlock("QPushButton#ClearButton", styles, sheet)

    styles = {
        "background-color": ACCENT.toRGBA(0.2),
        "border-radius": (FONTSIZE+MEDIUMPAD) / 4,
        "border-style": "none",
        "padding": "0 5",
    }
    addBlock("QLineEdit#EntryLine", styles, sheet)

    styles = {
        "background-color": ACCENT.toRGBA(0.2),
        "border-radius": (FONTSIZE+MEDIUMPAD) / 4,
        "border-style": "none",
        "padding": "0 5",
    }
    addBlock("QDateEdit#EntryDate", styles, sheet)


def getIconURL(iconname, color):
    return paintIcon(iconsdir+'/'+iconname+'.svg', color)

def main():
    sheet = open(sourcedir+"/styles/stylesheet.qss", "w+")
    sheet.write("")
    writeQSS(sheet)
    sheet.close()
    return 0


if __name__ == "__main__":
    FONTSIZE = int(sys.argv[1])
    sourcedir = sys.argv[2]
    iconsdir = sourcedir + "/icons"
    if len(sys.argv) > 3:
        colorscheme = sys.argv[3]
    if colorscheme not in colorschemes:
        raise NameError("Colorscheme not found.")
    CS = colorschemes[colorscheme]
    ACCENT = Color(CS["accent"])
    BACKGROUND = Color(CS["background"])
    FOREGROUND = Color(CS["foreground"])
    BRIGHTTEXT = Color(CS["brighttext"])
    main()
