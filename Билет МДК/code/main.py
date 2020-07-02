import matplotlib.pyplot as plt


from polynom import *
from StringGrid import *

if __name__ == "__main__":
    root = None 
    interval = None
    step = None
    # получаем степень полинома
    power = int(input('Polynomial degree = ')) 

    # объект StringGrid
    stringgrid = StringGrid()

    # настройки таблицы
    stringgrid.SetColCount(power + 1)
    stringgrid.SetRowCount(1)

    # вносим данные
    stringgrid.Add()

    print(stringgrid.Cells)

    # пока не получим верные данные запрашиваем их
    while not root:
        try:
            # получаем корни уравнения
            root = list(map(float, (*stringgrid.Cells)))
        except ValueError:
            print("Incorrect value.")
            root = None
            stringgrid.Add()
            print(stringgrid.Cells)

    # пока не получим верные данные запрашиваем их
    while not interval:
        try:
            # получаем интервал графика
            interval = list(map(int, (input('Enter interval(example: -4 4): ')).split()))
        except ValueError:
            print("Incorrect value.")
            interval = None

    # пока не получим верные данные запрашиваем их
    while not step:
        try:
            # получаем шаг
            step = float(input('Enter step: '))
        except ValueError:
            print("Incorrect value.")
            step = None
    

    pol = Polynom(root) # создаем объект полинома

    # устанавливаем заголовки окна графика
    plt.title(f"График полинома y(x) = {pol}")
    plt.xlabel("x") # ось абсцисс
    plt.ylabel("y") # ось ординат
    # plt.grid()      # включение отображение сетки

    # получаем списки координат для отрисовки
    [x, y] = pol.draw(interval, step)

    # выводим четность и нечетность полинома
    plt.text (x[round(len(x) / 4) * 3], y[-1], f"Odd: {pol.odd()}")
    plt.text (x[round(len(x) / 4) * 3], y[-1] - (((max(y) - min(y)) / 100) * 7), f"Even: {pol.even()}")

    # создаем график
    plt.plot(x, y, label=f"y(x) = {pol}")

    # создаем легенду
    plt.legend(loc="upper left")

    # отрисовка
    plt.show()
