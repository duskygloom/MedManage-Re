# classes and functions for styling

import os


class Color:
    def __init__(self, rgb: tuple):
        self.r = rgb[0]
        self.g = rgb[1]
        self.b = rgb[2]
        self.rgb = rgb

    def toRGB(self):
        string = f"rgb({self.r}, {self.g}, {self.b})"
        return string

    def toRGBA(self, opacity):
        alpha = opacity * 255
        string = f"rgba({self.r}, {self.g}, {self.b}, {alpha})"
        return string

    def toHex(self, opacity = 1):
        if opacity != 1:
            rgba = rgb + (int(255*opacity),)
            return "#%02x%02x%02x%02x" % rgba
        return "#%02x%02x%02x" % self.rgb


def addBlock(state, styles, fileobj):
    '''writes a qss cascade from the state and dictionary of styles'''
    string = state + " { "
    for i in styles:
        string += f"{i}: {styles[i]}; "
    string += "}\n"
    fileobj.write(fileobj.read() + string)
    fileobj.flush()

def paintIcon(svgpath, colorobj):
    '''sets fill colour to icons and returns the path of coloured svg
    color should be a Color object'''
    hexeq = colorobj.toHex()
    fpath = svgpath.rstrip(".svg")
    fpath += hexeq.lstrip("#") + ".svg"
    if not os.path.isfile(fpath):
        with open(svgpath, "r") as rfile:
            with open(fpath, "w") as wfile:
                lines = rfile.readlines()
                lines[1] = f'"fill: {hexeq}"\n'
                wfile.writelines(lines)
                wfile.flush()
    return fpath
