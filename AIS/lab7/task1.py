from frame import Frame

class Journal(Frame):
    def __init__(self):
        self.frame_name = "Журнал"
        self.title = ""
        self.target = None
        self.price = 0
        self.pages = 0
        self.description = ""
        self.subscription = None
        self.attributes = [
            ("frame_name", "Название фрейма"),
            ("title", "Название журнала"),
            ("target", "Целевая аудитория"),
            ("price", "Стоимость одного номера"),
            ("pages", "Объём страниц журнала"),
            ("description", "Описание журнала"),
            ("subscription", "Возможность подписки"),
        ]

    def set_data(self, title, target, price, pages, description, subscription):
        self.title = title
        self.target = target
        self.price = price
        self.pages = pages
        self.description = description
        self.subscription = subscription

    def __str__(self):
        t = ""
        if type(self.target) == type([]):
            for i in self.target:
                t += str(i) + " "
        else:
            t = str(self.target)
        return "{} | {} | {} | {} | {} | {} | {}".format(self.frame_name, self.title, t, self.price, self.pages, self.description, self.subscription)


class Target(Frame):
    def __init__(self):
        self.frame_name = "Целевая аудитория"
        self.target = ""
        self.attributes = [
            ("frame_name", "Название фрейма"),
            ("target", "Целевая аудитория"),
        ]

    def set_data(self, target):
        self.target = target

    def __str__(self):
        return "{}: {}".format(self.frame_name, self.target)

class Subscription(Frame):
    def __init__(self):
        self.frame_name = "Возможность подписки"
        self.option = ""
        self.attributes = [
            ("frame_name", "Название фрейма"),
            ("option", "Возможность подписки"),
        ]

    def set_data(self, option):
        self.option = option

    def __str__(self):
        return "{}: {}".format(self.frame_name, self.option)

#######################################################################################################################################

subscr = Subscription()
subscr.set_data("Да")
no_subscr = Subscription()
no_subscr.set_data("Нет")

men = Target()
men.set_data("Мужчины")
women = Target()
women.set_data("Женщины")
men_and_women = [men, women]

journals = [Journal() for j in range(6)]
journals[0].set_data("Тюнинг автомобилей", men, 140, 170, "Современные технологии тюнинга автомобилей", no_subscr)
journals[1].set_data("Мода", women, 90, 90, "Новейшие тенденции моды", no_subscr)
journals[2].set_data("Компьютерные и видео игры", men_and_women, 65, 60, "Всё о компьютерных и видеоиграх", no_subscr)
journals[3].set_data("Рукоделие", women, 45, 50, "Эксклюзивные вещи своими руками", subscr)
journals[4].set_data("Фотография", men_and_women, 100, 95, "Основы и секреты фотографии", subscr)
journals[5].set_data("Кино и музыка", men_and_women, 30, 30, "Только актуальная информация о кино и музыке", no_subscr)

#######################################################################################################################################

def eq(a, b):
    return a == b

def le(a, b):
    return a <= b


def search(source, func, second_arg, attr):
    res = []
    for item in source:
        t = item.getAttributeValue(attr)
        if type(t) == type([]):
            for l in t:
                if func(l, second_arg):
                    res.append(item)
                    break
        else:
            if func(t, second_arg):
                res.append(item)
    for r in res:
        print(r)

#######################################################################################################################################

print("\nКакой журнал предоставляет информацию о современных технологиях тюнинга автомобилей?")
search(journals, eq, "Современные технологии тюнинга автомобилей", "Описание журнала")
print("\nКакие журналы предназначены для мужчин?")
search(journals, eq, men, "Целевая аудитория")
print("\nКакие журналы стоят 100 рублей?")
search(journals, eq, 100, "Стоимость одного номера")
print("\nНа какие журналы можно оформить подписку?")
search(journals, eq, subscr, "Возможность подписки")
print("\nНайти все журналы издательства")
search(journals, eq, "Журнал", "Название фрейма")
print("\nКакие журналы стоят не более 150 рублей?")
search(journals, le, 150, "Стоимость одного номера")
