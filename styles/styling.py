# This Python file uses the following encoding: utf-8
# file executed like styling.py FONTSIZE filedir colorscheme

import sys
from colorschemes import *
from stylingclass import *


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

    styles = { "background-color": ACCENT.toRGBA(0.4) }
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

    styles = { "padding": "0 2" }
    addBlock("QLabel#NotifLabel", styles, sheet)
    addBlock("QLabel#TimeLabel", styles, sheet)

    styles = { "background-color": ACCENT.toRGBA(0.9) }
    addBlock("QPushButton#ClearButton:hover", styles, sheet)

    styles = { "background-color": ACCENT.toRGB() }
    addBlock("QPushButton#ClearButton:pressed", styles, sheet)

    styles = {
        "background-color": ACCENT.toRGBA(0.8),
        "border-radius": (FONTSIZE+LARGEPAD) / 4,
        "border-style": "none",
        "qproperty-icon": f"url({getIconURL('clear_all', BACKGROUND)})",
    }
    addBlock("QPushButton#ClearButton", styles, sheet)

    styles = {
        "background-color": FOREGROUND.toRGBA(0.1),
        "border-radius": (FONTSIZE+LARGERPAD) / 4,
        "border-style": "none",
        "padding": "2 5",
    }
    addBlock("QLineEdit#EntryLine", styles, sheet)

    styles = {
        "border": f"1px solid {ACCENT.toRGB()}",
    }
    addBlock("QLineEdit:focus#EntryLine", styles, sheet)

    styles = {
        "background-color": FOREGROUND.toRGBA(0.1),
        "border-radius": (FONTSIZE+LARGERPAD) / 4,
        "border-style": "none",
        "padding": "2 5",
    }
    addBlock("QDateEdit#EntryDate", styles, sheet)

    styles = {
        "border": f"1px solid {ACCENT.toRGB()}",
    }
    addBlock("QLineEdit:focus#EntryLine", styles, sheet)

    styles = {
        "subcontrol-origin": "content",
        "subcontrol-position": "top right",
        "border-style": "none",
        "border-top-left-radius": (FONTSIZE+LARGEPAD) // 4,
        "border-top-right-radius": (FONTSIZE+LARGEPAD) // 4,
        "background": ACCENT.toRGBA(0.8),
        "height": (FONTSIZE+LARGEPAD) / 2,
        "width": (FONTSIZE+LARGEPAD) / 2,
    }
    addBlock("QDateEdit::up-button#EntryDate", styles, sheet)

    styles = { "background": ACCENT.toRGBA(0.9) }
    addBlock("QDateEdit::up-button:hover#EntryDate", styles, sheet)

    styles = { "background": ACCENT.toRGB() }
    addBlock("QDateEdit::up-button:pressed#EntryDate", styles, sheet)

    styles = {
        "subcontrol-origin": "content",
        "subcontrol-position": "bottom right",
        "border-style": "none",
        "border-bottom-left-radius": (FONTSIZE+LARGEPAD) // 4,
        "border-bottom-right-radius": (FONTSIZE+LARGEPAD) // 4,
        "background": ACCENT.toRGBA(0.8),
        "height": (FONTSIZE+LARGEPAD) / 2,
        "width": (FONTSIZE+LARGEPAD) / 2,
    }
    addBlock("QDateEdit::down-button#EntryDate", styles, sheet)

    styles = { "background": ACCENT.toRGBA(0.9) }
    addBlock("QDateEdit::down-button:hover#EntryDate", styles, sheet)

    styles = { "background": ACCENT.toRGB() }
    addBlock("QDateEdit::down-button:pressed#EntryDate", styles, sheet)

    styles = {
        "image": f"url({getIconURL('arrow_up', BACKGROUND)})",
        "width": (FONTSIZE+LARGERPAD) / 2,
        "height": (FONTSIZE+LARGERPAD) / 2,
    }
    addBlock("QDateEdit::up-arrow#EntryDate", styles, sheet)

    styles = {
        "image": f"url({getIconURL('arrow_down', BACKGROUND)})",
        "width": (FONTSIZE+LARGERPAD) / 2,
        "height": (FONTSIZE+LARGERPAD) / 2,
    }
    addBlock("QDateEdit::down-arrow#EntryDate", styles, sheet)


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
