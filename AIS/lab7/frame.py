class Frame:
    def __init__(self):
        self.attributes = []
        self.name = "Фрейм"

    def getAttributeValue(self, name):
        attr = ""
        for a in self.attributes:
            if a[1].upper() == name.upper():
                attr = a[0]
        if attr == "":
            return None
        return getattr(self, attr)