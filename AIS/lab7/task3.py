from frame import Frame

class Date(Frame):
    def __init__(self):
        self.frame_name = "Дата"
        self.date = ""
        self.time = ""
        self.attributes = [
            ("date", "День"),
            ("time", "Время")
        ]
    
    def set_data(self, date, time):
        self.date = date
        self.time = time

    def __str__(self):
        return "{} : {} {}".format(self.frame_name, self.date, self.time)

class Location(Frame):
    def __init__(self):
        self.frame_name = "Место проведения"
        self.location = ""
        self.attributes = [
            ("location", "Место проведения")
        ]
    
    def set_data(self, location):
        self.location = location

    def __str__(self):
        return "{} : {}".format(self.frame_name, self.location)

class Topic(Frame):
    def __init__(self):
        self.frame_name = "Тема выступления"
        self.topic = ""
        self.attributes = [
            ("topic", "Тема выступления")
        ]
    
    def set_data(self, topic):
        self.topic = topic

    def __str__(self):
        return "{} : {}".format(self.frame_name, self.topic)

class Purpose(Frame):
    def __init__(self):
        self.frame_name = "Цель выступления"
        self.purpose = ""
        self.attributes = [
            ("purpose", "Цель выступления")
        ]
    
    def set_data(self, purpose):
        self.purpose = purpose

    def __str__(self):
        return "{} : {}".format(self.frame_name, self.purpose)

class Human(Frame):
    def __init__(self):
        self.frame_name = "Человек"
        self.name = ""
        self.age = 0
        self.attributes = [
            ("name", "Имя"),
            ("age", "Возраст")
        ]
    
    def set_data(self, name, age):
        self.name = name
        self.age = age

    def __str__(self):
        return "{} : {} {}".format(self.frame_name, self.name, self.age)

class Speaker(Frame):
    def __init__(self):
        self.frame_name = "Выступающий"
        self.speaker_number = ""
        self.human = None
        self.attributes = [
            ("speaker_number", "Номер выступающего"),
            ("human", "Человек")
        ]
    
    def set_data(self, speaker_number, human):
        self.speaker_number = speaker_number
        self.human = human

    def __str__(self):
        return "{} : {} {}".format(self.frame_name, self.speaker_number, self.human)

class Presentation(Frame):
    def __init__(self):
        self.frame_name = "Выступление"
        self.topic = None
        self.purpose = None
        self.speaker = None
        self.attributes = [
            ("topic", "Тема"),
            ("purpose", "Цель"),
            ("speaker", "Выступающий")
        ]

    def set_data(self, topic, purpose, speaker):
        self.topic = topic
        self.purpose = purpose
        self.speaker = speaker

    def __str__(self):
        return "{} : {} {} {}".format(self.frame_name, self.topic, self.purpose, self.speaker)

class Conference(Frame):
    def __init__(self):
        self.frame_name = "Конференция"
        self.name = ""
        self.date_time = None
        self.location = None
        self.presentations = []
        self.attributes = [
            ("name", "Название"),
            ("date_time", "Дата и время проведения"),
            ("location", "Место проведения"),
            ("presentations", "Выступления")
        ]
    
    def set_data(self, name, date_time, location, presentations):
        self.name = name
        self.date_time = date_time
        self.location = location
        self.presentations = presentations

    def __str__(self):
        return "{} : {} {} {} {}".format(self.frame_name, self.name, self.date_time, self.location, self.presentations)

#######################################################################################################################################

date = Date()
date.set_data("06.01.2021", "12:00")

loc = Location()
loc.set_data("Белгород, на связи")

topics = [Topic() for t in range(3)]
topics[0].set_data("Как стать акционером")
topics[1].set_data("Вкладываемся в производство масок")
topics[2].set_data("Светлое будущее Фуфелшмерц Корпорэйшн")

purposes = [Purpose() for p in range(3)]
purposes[0].set_data("Анализ рынка акций и живой пример вложения")
purposes[1].set_data("Обзор рынка медицинских масок, оценка возможностей развития")
purposes[2].set_data("Разработаем рабочий план поимки Перри-Утконоса")

humans = [Human() for h in range(3)]
humans[0].set_data("Артемьев В.С.", 45)
humans[1].set_data("Ермоленко Г.Г.", 30)
humans[2].set_data("Хайнц Фуфелшмертц", 47)

speakers = [Speaker() for s in range(3)]
speakers[0].set_data("1", humans[0])
speakers[1].set_data("3", humans[1])
speakers[2].set_data("2", humans[2])

presentations = [Presentation() for p in range(3)]
presentations[0].set_data(topics[0], purposes[0], speakers[0])
presentations[1].set_data(topics[1], purposes[1], speakers[1])
presentations[2].set_data(topics[2], purposes[2], speakers[2])

conference = Conference()
conference.set_data("Первая галактическая конференция", date, loc, presentations)

#######################################################################################################################################

def eq(a, b):
    return a == b

def eqobj(a, b):
    s1 = str(a)
    s2 = str(b)
    # print(s1, s2, s1 == s2)
    return s1 == s2

def le(a, b):
    return a <= b

def ge(a, b):
    return a >= b

def ne(a, b):
    return a != b

def all(a, b):
    return True

def rec_search(source, func, second_arg, attr):
    res = []
    for item in source:
        t = item.getAttributeValue(attr)
        if t == None:
            for a in item.attributes:
                t1 = item.getAttributeValue(a[1])
                if type(t1) == type([]):
                    tmp = rec_search(t1, func, second_arg, attr)
                    if tmp != []:
                         res = tmp
                        # res.append(tmp)
                else:
                    if isinstance(t1, Date) or isinstance(t1, Location) or isinstance(t1, Topic) or isinstance(t1, Purpose) or isinstance(t1, Human) or isinstance(t1, Speaker) or isinstance(t1, Presentation):
                        tmp = rec_search([t1], func, second_arg, attr)
                        if tmp != []:
                            res.append(tmp)
                            break
        else:
            if func(t, second_arg):
                # res.append(t)
                 res.append(item)
                # res.append(str(item))
                    #tmp
    return res


def parser(mes):
    print()
    print(mes)
    if mes.find("?") != -1:
        mes = mes[:len(mes)-1]
    templates = [
        ("Кто выступает","под номером", "на тему"),
        ("Какие", "темы", "цели"),
        ("Какое", ""),
        ("Какую", "тему", "цель") 
    ]
    if mes.find(templates[0][0]) != -1:
        if mes.find(templates[0][1]) != -1:
            k = mes.split(" ")[-1]
            res = rec_search([conference], eq, k, "Номер выступающего")
            for r in res:
                print(*r)
            print()
        else:
            if mes.find(templates[0][2]) != -1:            
                str_ = mes[mes.find("на тему") + 8:]
                res = rec_search([conference], eq, str_, "Тема выступления")
                # print(res)
                res = rec_search([conference], eqobj, res[0][0], "Тема")
                res = rec_search(res, all, 0, "Человек")
                for r in res[0]:
                    print(r)
                print()
            else:
                res = rec_search([conference], all, 0, "Человек")
                for r in res:
                    print(*r)
                print()

    if mes.find(templates[1][0]) != -1:
        if mes.find(templates[1][1]) != -1:
            res = rec_search([conference], all, 0, "Тема выступления")
            for r in res:
                print(*r)
            print()
        else:
            if mes.find(templates[1][2]) != -1:
                res = rec_search([conference], all, 0, "Цель выступления")
                for r in res:
                    print(*r)
                print()
    if mes.find(templates[2][0]) != -1:
        str_ = mes[mes.find("подготовил") + 11:]
        res = rec_search([conference], eq, str_, "Имя")
        # print(res)
        res = rec_search([conference], eqobj, res[0][0][0], "Выступающий")
        print(res)
        # res = rec_search(res[0], all, 0, "Тема выступления")
        # print(res)
        # res = rec_search(res, all, 0, "Тема")
        # for r in res:
        #     print(r)
        # print()
    if mes.find(templates[3][0]) != -1:
        print(7)

#######################################################################################################################################

parser("Кто выступает?")
parser("Какие будут темы выступлений?")
parser("Какие будут цели выступлений?")
parser("Кто выступает на тему Как стать акционером?")
# parser("Какое выступление подготовил Артемьев В.С.?")
parser("Кто выступает под номером 2?")