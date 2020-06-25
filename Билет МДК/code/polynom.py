import numpy

# класс полинома
class Polynom:
    def __init__(self, root):
        self.root = root # корни уравнения

    # строковое представление объекта
    def __repr__(self):
        l = len(self.root)
        stra = []
        for r in self.root:
            l = l - 1
            if r:
                stra.append(''.join([str(r) if r != 1 else '', 'x' if l else '', f'^{l}' if l > 1 else '']))
        return ' + '.join(stra)

    def f(self, x):
        """
        получение f(x) для любого x

        Args:
            self: Объект класса.
            x: Любой x.

        Returns:
            res: f(x).

        Raises:
            
        """
        l = len(self.root)
        res = 0
        for r in self.root:
            l = l - 1
            res += r * pow(x, l)
        return res

    def even(self):
        """
        четная ли функция

        Args:
            self: Объект класса.

        Returns:
            {bool}: Да или нет.

        Raises:
            
        """
        test = [i for i in range(1, 10)]

        res = [self.f(i) == self.f(-i) for i in test]

        if False in res:
            return False
        return True

    def odd(self):
        """
        нечетная ли функция

        Args:
            self: Объект класса.

        Returns:
            {bool}: Да или нет.

        Raises:
            
        """
        test = [i for i in range(1, 10)]

        res = [self.f(i) == -(self.f(-i)) for i in test]

        if False in res:
            return False
        return True

    def draw(self, interval, step):
        """
        нечетная ли функция

        Args:
            self: Объект класса.
            interval: интервал координат
            step: шаг

        Returns:
            [x, y]: Список координат.

        Raises:
            
        """
        [intervalL, intervalR] = interval
        y = []
        yR = []
        x = [i for i in numpy.arange(intervalL, intervalR + step, step)]

        y = [self.f(i) for i in x]

        return [x, y]