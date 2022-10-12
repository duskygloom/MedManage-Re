# classes and functions for styling

class Color:
    def __init__(self, rgb: tuple):
        self.r = rgb[0]
        self.g = rgb[1]
        self.b = rgb[2]

    def toRGB(self):
        string = f"rgb({self.r}, {self.g}, {self.b})"
        return string

    def toRGBA(self, opacity):
        alpha = opacity * 255
        string = f"rgba({self.r}, {self.g}, {self.b}, {alpha})"
        return string


def addBlock(state, styles, fileobj):
    '''writes a qss cascade from the state and dictionary of styles'''
    string = state + " { "
    for i in styles:
        string += f"{i}: {styles[i]}; "
    string += "}\n"
    fileobj.write(fileobj.read() + string)
    fileobj.flush()
