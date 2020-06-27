class Stancia:#Класс для хранения информации о станциях
    def __init__(self, stanciaid, name):
        self.Stancia_ID = stanciaid
        self.Stancia_name = name


class Avtobus:#Класс для хранения информации об автобусах
    def __init__(self, avtobusid, mark, number, places):
        self.Avtobus_ID = avtobusid
        self.Avtobus_mark = mark
        self.Number = number
        self.Places = places


class People:#Класс для хранения информации о рейсах"""
    def __init__(self, peopleid, stanciaid, avtobusid, time):
        self.People_ID = peopleid
        self.Stancia_ID = stanciaid
        self.Avtobus_ID = avtobusid
        self.Time = time
