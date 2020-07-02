import msvcrt, sys

class StringGrid:
    def __init__(self):
        self.ColCount = 5
        self.RowCount = 5

        self.Row = ['' for i in range(self.ColCount)]
        self.Cells = [self.Row for i in range(self.RowCount)]

    def SetColCount(self, n):
        """
        Установка количества столбцов

        Args:
            self: Объект класса.
            n: количество

        Returns:

        Raises:
        """ 
        self.ColCount = n

        self.Row = ['' for i in range(self.ColCount)]
        self.Cells = [self.Row for i in range(self.RowCount)]

    def SetRowCount(self, n):
        """
        Установка количества строк

        Args:
            self: Объект класса.
            n: количество

        Returns:

        Raises:
        """ 
        self.RowCount = n

        self.Row = ['' for i in range(self.ColCount)]
        self.Cells = [self.Row for i in range(self.RowCount)]
        

    def Add(self):
        """
        Добавление значений в таблицу

        Args:
            self: Объект класса.

        Returns:

        Raises:
        """    
        i = 0
        j = 0
        
        num = [str(i) for i in range(0, 10)]
        arrow = False
        c = ''
        add = True
        edit = False
        print(f"StringGrid.Cells[0][0] = ",end="") 
        print('\r', end='')
        while add:
            # отслеживание нажатий клавиш
            pressedKey = msvcrt.getch()
            if pressedKey == b'\x1b':
                add = False
                print()
                if c != '':
                    self.Cells[i][j] = c
                    c = ''
            if pressedKey == b'\r':
                if c != '':
                    self.Cells[i][j] = c
                    c = ''
            elif pressedKey == b'\xe0':
                arrow = True
                if c != '':
                    self.Cells[i][j] = c
                    c = '' 

            elif pressedKey == b'-':
                if c == '':
                    c += '-'
                    print(f"StringGrid.Cells[{i}][{j}] = {''.join([c, ''.join([' ' for i in range(20)])])}",end="")
                    print('\r', end='')

            elif pressedKey == b'.' or pressedKey == b',':
                if not '.' in c and c != '':
                    c += '.'
                    print(f"StringGrid.Cells[{i}][{j}] = {''.join([c, ''.join([' ' for i in range(20)])])}",end="")
                    print('\r', end='')

            elif arrow and pressedKey == b'M':
                if j < self.ColCount - 1:
                    j += 1
                print(f"StringGrid.Cells[{i}][{j}] = {''.join([self.Cells[i][j], ''.join([' ' for i in range(20)])]) if self.Cells[i][j] != '' else ''.join([' ' for i in range(20)])}",end="")
                print('\r', end='')
                arrow = False
            elif arrow and  pressedKey == b'K':
                if j > 0:
                    j -= 1
                print(f"StringGrid.Cells[{i}][{j}] = {''.join([self.Cells[i][j], ''.join([' ' for i in range(20)])]) if self.Cells[i][j] != '' else ''.join([' ' for i in range(20)])}",end="")
                print('\r', end='')
                arrow = False
            elif arrow and  pressedKey == b'H':
                if i > 0:
                    i -= 1
                print(f"StringGrid.Cells[{i}][{j}] = {''.join([self.Cells[i][j], ''.join([' ' for i in range(20)])]) if self.Cells[i][j] != '' else ''.join([' ' for i in range(20)])}",end="")
                print('\r', end='')
                arrow = False
            elif arrow and pressedKey == b'P':
                if i < self.RowCount - 1:
                    i += 1
                print(f"StringGrid.Cells[{i}][{j}] = {''.join([self.Cells[i][j], ''.join([' ' for i in range(20)])]) if self.Cells[i][j] != '' else ''.join([' ' for i in range(20)])}",end="")
                print('\r', end='')
                arrow = False
            elif pressedKey == b'\x08':
                c = c[:-1]
                print(f"StringGrid.Cells[{i}][{j}] = {''.join([c, ''.join([' ' for i in range(20)])])}",end="")
                print('\r', end='')
            elif not arrow and pressedKey.decode() in num:
                c += pressedKey.decode()
                print(f"StringGrid.Cells[{i}][{j}] = {c}",end="")
                print('\r', end='') 
