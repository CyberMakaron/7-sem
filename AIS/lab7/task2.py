from frame import Frame

class AmphibiousVehicle(Frame):
    def __init__(self):
        self.frame_name = "Десантное средство"
        self.name = ""
        self.type = None
        self.capacity = 0
        self.weapon = None
        self.protection = None

        self.attributes = [
            ("frame_name", "Десантное средство"),
            ("name", "Наименование"),
            ("type", "Способ передвижения"),
            ("capacity", "Вместимость"),
            ("weapon", "Вооружение"),
            ("protection", "Защита")
        ]

    def set_data(self, name, transporting_type, capacity, weapon, protection):
        self.name = name
        self.type = transporting_type
        self.capacity = capacity
        self.weapon = weapon
        self.protection = protection

    def __str__(self):
        return "{} | {} | {} | {} | {} | {}".format(self.frame_name, self.name, self.type, self.capacity, self.weapon, self.protection)

class TransporingType(Frame):
    def __init__(self):
        self.frame_name = "Способ передвижения"
        self.type = ""

        self.attributes = [
            ("frame_name", "Десантное средство"),
            ("type", "Способ передвижения")
        ]

    def set_data(self, type):
        self.type = type

    def __str__(self):
        return "{}: {}".format(self.frame_name, self.type)

class Weapon(Frame):
    def __init__(self):
        self.frame_name = "Вооружение"
        self.type = ""
        self.caliber = ""

        self.attributes = [
            ("frame_name", "Десантное средство"),
            ("type", "Тип вооружения"),
            ("caliber", "Калибр")
        ]

    def set_data(self, type, caliber):
        self.type = type
        self.caliber = caliber

    def __str__(self):
        if self.caliber != "":
            return "{} : {} {}".format(self.frame_name, self.type, self.caliber)
        return "{} : {}".format(self.frame_name, self.type)

class Protection(Frame):
    def __init__(self):
        self.frame_name = "Защита"
        self.type = ""

        self.attributes = [
            ("frame_name", "Защита"),
            ("type", "Тип защиты"),
        ]

    def set_data(self, type):
        self.type = type

    def __str__(self):
        return "{} : {}".format(self.frame_name, self.type)


#######################################################################################################################################

transporting_types = [TransporingType() for tt in range(3)]
transporting_types[0].set_data("Гусеницы")
transporting_types[1].set_data("Вертолет")
transporting_types[2].set_data("Колеса")

weapons = [Weapon() for _ in range(4)]
weapons[0].set_data("Пушка", "100 мм")
weapons[1].set_data("Пушка", "30 мм")
weapons[2].set_data("Пулемет", "14,5 мм")
weapons[3].set_data("Нет", "")

protections = [Protection() for _ in range(3)]
protections[0].set_data("Броня")
protections[1].set_data("Сталь")
protections[2].set_data("Нет")

amphibious_vehicles = [AmphibiousVehicle() for _ in range(4)]
amphibious_vehicles[0].set_data("БМП-3", transporting_types[0], 7, weapons[0], protections[0])
amphibious_vehicles[1].set_data("Ми-24", transporting_types[1], 6, weapons[1], protections[1])
amphibious_vehicles[2].set_data("БТР-50Б", transporting_types[2], 8, weapons[2], protections[0])
amphibious_vehicles[3].set_data("Ми-8", transporting_types[1], 12, weapons[3], protections[2])

#######################################################################################################################################

def eq(a, b):
    return a == b

def le(a, b):
    return a <= b

def ge(a, b):
    return a >= b

def ne(a, b):
    return a != b

def rec_check(source, func, second_arg, attr):
    res = False
    if type(source) != type(None):
        t = source.getAttributeValue(attr)
        if func(t, second_arg) and t != None:
            res = True
    return res

def search(source, func, second_arg, attr):
    res = []
    for item in source:
        t = item.getAttributeValue(attr)
        if t == None:
            for a in item.attributes:
                t1 = item.getAttributeValue(a[1])
                if isinstance(t1, TransporingType) or isinstance(t1, Weapon) or isinstance(t1, Protection):
                    if rec_check(t1, func, second_arg, attr):
                        res.append(item)
                        break
        else:
            if isinstance(t, TransporingType) or isinstance(t, Weapon) or isinstance(t, Protection):
                if rec_check(t, func, second_arg, attr):
                    res.append(item)
            else:
                if func(t, second_arg):
                    res.append(item)

    return res

#######################################################################################################################################

print("\n1. Вертолет, способный перевозить не менее 6 человек десанта над полем боя без поддержки наземных средств")
res = search(amphibious_vehicles, eq, "Вертолет", "Способ передвижения")
res = search(res, ge, 6, "Вместимость")
res = search(res, ne, "Нет", "Тип вооружения")
for r in res:
    print(r)

print("\n2. Наземное средство доставки не менее 6 десантников в тыл противника при активном противодействии бронетанковых войск противника")
res = search(amphibious_vehicles, ne, "Вертолет", "Способ передвижения")
res = search(res, ge,  6, "Вместимость")
res = search(res, eq, "Броня", "тип защиты")
res = search(res, eq, "Пушка", "Тип вооружения")
for r in res:
    print(r)

print("\n3. Средство доставки не менее 6 человек десанта в тыл противника при наличии противодействия противника.")
res = search(amphibious_vehicles, ge, 6, "Вместимость")
res = search(res, ne, "Нет", "тип защиты")
res = search(res, ne, "Нет", "Тип вооружения")
for r in res:
    print(r)

print()