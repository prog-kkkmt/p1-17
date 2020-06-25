import matplotlib.pyplot as plt


from polynom import *

if __name__ == "__main__":
	# получаем корни уравнения
	root = list(map(float, (input('Enter roots of polynom(example: 1 2 3 4 5): ')).split()))
	# получаем интервал графика
	interval = list(map(int, (input('Enter interval(example: -4 4): ')).split()))
	# получаем шаг
	step = float(input('Enter step: '))

	pol = Polynom(root) # создаем объект полинома

	# устанавливаем заголовки окна графика
	plt.title(f"График полинома y(x) = {pol}")
	plt.xlabel("x") # ось абсцисс
	plt.ylabel("y") # ось ординат
	# plt.grid()      # включение отображение сетки

	# получаем списки координат для отрисовки
	[x, y] = pol.draw(interval, step)

	# выводим четность и нечестность функции
	plt.text (x[round(len(x) / 4) * 3], y[-1], f"Odd: {pol.odd()}")
	plt.text (x[round(len(x) / 4) * 3], y[-1] - (((max(y) - min(y)) / 100) * 7), f"Even: {pol.even()}")

	# создаем график
	plt.plot(x, y, label=f"y(x) = {pol}")

	# создаем легенду
	plt.legend(loc="upper left")

	# отрисовка
	plt.show()
