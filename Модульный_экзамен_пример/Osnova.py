import Bus as B

def start(stations, buses):
    """Функция для получения данных из таблицы"""
    with open("Станции.txt") as f:
        for line in f.readlines():
            st = B.Stancia(*line.split())
            stations[st.Station_ID] = [st.Station_name, 0]

    with open("Автобусы.txt") as f:
        for line in f.readlines():
            bus = B.Avtobus(*line.split())
            buses[bus.Bus_ID] = [int(bus.Places), 0]

    with open("Рейсы.txt") as f:
        for line in f.readlines():
            pas = B.People(*line.split())
            for station in stations:
                if station == pas.Station_ID:
                    stations[station][1] += 1
            for bus in buses:
                if bus == pas.Bus_ID:
                    buses[bus][1] += 1


def passages(stations):
    """Функция для вывода количества рейсов до каждой станции"""
    for station in stations:
        print("Количество рейсов, выполняемых до станции", stations[station][0], "-", stations[station][1])


def number_of_passengers(buses):
    """Функция для вывода общего числа пассажиров"""
    k = 0
    for bus in buses:
        k += buses[bus][0] * buses[bus][1]
    print("Общее количество пассажиров -", k)


if __name__ == "__main__":
    stations = dict()
    buses = dict()
    start(stations, buses)
    passages(stations)
    number_of_passengers(buses)
