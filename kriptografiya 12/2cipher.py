#алгоритм Диффи-Хеллмана
import random

print('Введите 2 числа: ')
g = int(input())
p = int(input())
a = random.randint(10000000,100000000)
b = random.randint(10000000,100000000)
A = g ** a % p
B = g ** b % p
K1 = B ** a % p
K2 = A ** b % p
if K1 == K2:
    print('Успешно.')
