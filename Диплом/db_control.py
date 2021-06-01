import pyodbc


class DbControl:
    def __init__(self):
        """Конструктор класса DbControl"""
        super(DbControl, self).__init__()
        _driver = "Driver={SQL server}"
        _server = "Server={0}"
        _data_base = "Database={Контингент}"
        _trust = "Trust_Connection=yes"
        _config = open("Config.txt", "r")
        _data = _config.readline()
        _config.close()
        _conn_str = ';'.join([_driver, _server.format(_data), _data_base, _trust])
        self.conn = pyodbc.connect(_conn_str)
        self.cursor = self.conn.cursor()

    def insert_data(self, course, info, statistic):
        """Добавление данных из Excel в БД"""
        self.cursor.execute("EXEC [Добавление данных] @dir_id = ?, @dir_name = ?, @foe_name = ?, @loe_name = ?, "
                            "@date = ?, @course = ?, @free_in = ?, @disabled_fi = ?, @target_fi = ?, "
                            "@foreigners_fi = ?, @pay_in = ?, @disabled_pi = ?, @target_pi = ?, @foreigners_pi = ?, "
                            "@free_out = ?, @disabled_fo = ?, @target_fo = ?, @foreigners_fo = ?, @pay_out = ?, "
                            "@disabled_po = ?, @target_po = ?, @foreigners_po = ?", info[1], info[2], info[3], info[0],
                            info[4], course, statistic[0], statistic[1], statistic[2], statistic[3], statistic[4],
                            statistic[5], statistic[6], statistic[7], statistic[8], statistic[9], statistic[10],
                            statistic[11], statistic[12], statistic[13], statistic[14], statistic[15])
        self.cursor.commit()

    def get_data(self, loe, foe, direction, year, month, course=0):
        """Получение данных из БД по выбранным параметрам"""
        if course == "Все":
            course = 0
        if month == "0":
            self.cursor.execute("EXEC [Получение данных] @loe_name = ?, @foe_name = ?, @dir_name = ?, @year = ?, "
                                "@course = ?", loe, foe, direction, year, course)
        else:
            if len(month) < 2:
                month = "0" + month
            self.cursor.execute("EXEC [Получение данных] @loe_name = ?, @foe_name = ?, @dir_name = ?, @year = ?, "
                                "@month = ?, @course = ?", loe, foe, direction, year, month, course)
        data = self.cursor.fetchall()
        return data

    def get_directions(self, loe):
        """Получение всех направлений подготовки определенного уровня обучения"""
        self.cursor.execute("EXEC [Получение направлений] @loe_name = ?", loe)
        data = self.cursor.fetchall()
        data = list(map("".join, list(map(list, data))))
        return data

    def get_years(self, loe):
        """Получение списка лет за которые хранятся данные определенного уровня обучения"""
        self.cursor.execute("EXEC [Получение лет] @loe_name = ?", loe)
        data = self.cursor.fetchall()
        info = list()
        for i in data:
            info.append(str(*i))
        return info

    def get_months(self, loe):
        """Получение списка лет за которые хранятся данные определенного уровня обучения"""
        self.cursor.execute("EXEC [Получение месяцев] @loe_name = ?", loe)
        data = self.cursor.fetchall()
        info = list()
        for i in data:
            info.append(str(*i))
        return info
