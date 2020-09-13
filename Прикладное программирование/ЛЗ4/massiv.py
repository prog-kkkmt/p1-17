def filling(i, n):
    mas_inner = []
    for i in range(n):
        mas_inner.append(int(input()))
    return mas_inner

def fmax(mas):
    return max(mas)

def fsum(mas):
    return sum(mas)

def printout(mas):
    print(mas, sep=' ')
   
a = 'choice'
mas = []
while a != '0':
    print('''1. Заполнение массива
2. Нахождение максимального
3. Нахождение суммы
4. Печать
0. Выход
>''', end='')
    a = input()
    if a == '1':
        mas = filling(0, 10)
    elif a == '2':
        print('max =', fmax(mas))
    elif a == '3':
        print('sum =', fsum(mas))
    elif a == '4':
        printout(mas)
