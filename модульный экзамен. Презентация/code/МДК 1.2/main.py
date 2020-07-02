import mysql.connector
from mysql.connector import Error
import configparser 
import os.path

from station import *
from bus import *
from flight import *

if __name__ == '__main__':
    config = configparser.ConfigParser()
    config_name = 'config.ini'

    if os.path.isfile(config_name):
        config.read(config_name)
        dbINI = config['DEFAULT']

        try:
            mys = mysql.connector.connect(host=dbINI['host'] ,database=dbINI['database'], user=dbINI['user'], password=dbINI['password'])
        
        except Error as e:
            print(e)

        else:
            if mys.is_connected():
                print(f"Connected to {dbINI['host']}")
                print(f"DataBase Name: {dbINI['database']}")
                print()
                cursor = mys.cursor()

                cursor.execute("SELECT * FROM station ORDER BY name")

                results = cursor.fetchall()

                stations = []

                for res in results:
                    stations.append(Station(res[0], res[1]))

                for station in stations:
                    cursor.execute(f"SELECT * FROM flights WHERE idstation = {station.getId()}")

                    results = cursor.fetchall()

                    flights = []

                    for res in results:
                        flights.append(Flight(res[0], res[1], res[2], res[3]))

                    print(f"{station}: Рейсов - {len(flights)}, ", end="")

                    idsBus = [flight.getIdBus() for flight in flights]

                    q = ' OR '.join([f"id = {idBus}" for idBus in idsBus])

                    cursor.execute(f"SELECT * FROM bus WHERE {q}")

                    results = cursor.fetchall()

                    buss = []
                    for res in results:
                        buss.append(Bus(res[0], res[1], res[2], res[3]))

                    cap = 0
                    for bus in buss:
                        cap += bus.getCapacity()

                    print(f" общая вместимость - {cap}")
            else:
                print('connection failed.')

            mys.close()
            
    else:
        print(f"Конфигурационный файл отсутствует!")