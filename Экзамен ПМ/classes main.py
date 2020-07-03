import pandas as pd
#класс для работы с таблицей “Маршруты”
class Table1:
    def __init__(self, event_type_code, type_name):
        self.event_type_code = event_type_code
        self.type_name = type_name

    def PrintOut1():
        df1 = pd.read_excel('Tourism.xlsx')
        print(df1[['Route Code', 'Route Name', 'Route Time', 'Route Category']])
#класс для работы с таблицей “Руководители”
class Table2:
    def __init__(self, event_type_code, type_name):
        self.event_type_code = event_type_code
        self.type_name = type_name

    def PrintOut2():
        df2 = pd.read_excel('Tourism.xlsx')
        print(df2[["Leader's Code", 'NSL', 'Phone Number']])

#класс для работы с таблицей “Группы”
class Table3:
    def __init__(self, event_code, event_type_code, event_name, start_time, full_time, done_tick):
        self.event_code = event_code
        self.event_type_code = event_type_code
        self.event_name = event_name
        self.start_time = start_time
        self.full_time = full_time
        self.done_tick = done_tick

    def PrintOut3():
        df3 = pd.read_excel('Group_Data.xlsx')
        print(df3)

    def PrintRoutes():
        df3 = pd.read_excel('Group_Data.xlsx')
        print(df3[["Group Name", "Route Code"]])

# функция для цикла с главным меню
def MainMenu():
    print('Выберите действие:')
    print('1: Вывести первую таблицу')
    print('2: Вывести вторую таблицу')
    print('3: Вывести третью таблицу')
    print('4: Вывести список групп и их маршрутов')
    print('0: Выход')
    cycle = input('>')
    return cycle


cycle = MainMenu()
# цикл выбора пунктов в главном меню
while cycle != '0':
    if cycle == '1':
        Table1.PrintOut1()
    elif cycle == '2':
        Table2.PrintOut2()
    elif cycle == '3':
        Table3.PrintOut3()
    elif cycle == '4':
        Table3.PrintRoutes()
    else:
        print('Неизвестное действие, используйте предложенный выбор.')
    cycle = MainMenu()
