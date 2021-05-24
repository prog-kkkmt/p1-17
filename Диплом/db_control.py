import pyodbc


class DbControl:
    def __init__(self):
        super(DbControl, self).__init__()
        _driver = 'Driver={SQL server}'
        _server = 'Server={0}'
        _data_base = 'Database={Контингент}'
        _trust = 'Trust_Connection=yes'
        _config = open('Config.txt', 'r')
        _data = _config.readline()
        _config.close()
        _conn_str = ';'.join([_driver, _server.format(_data), _data_base, _trust])
        self.conn = pyodbc.connect(_conn_str)
        self.cursor = self.conn.cursor()

    def test(self):
        self.cursor.execute('SELECT * FROM Направления')
        data = self.cursor.fetchall()
        return data
