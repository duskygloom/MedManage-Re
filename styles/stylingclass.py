# classes and functions for styling

class Color:
    def __init__(self, red, green, blue):
        self.r = red
        self.g = green
        self.b = blue

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
