'''
Когда Павел учился в школе, он запоминал таблицу умножения прямоугольными блоками. Для тренировок ему бы очень пригодилась программа, которая показывала бы блок таблицы умножения.
Sample Input 1:
7
10
5
6
Sample Output 1:
	5	6
7	35	42
8	40	48
9	45	54
10	50	60
'''

a =int (input())
b =int (input())
c =int (input())
d =int (input())
for m in range (c,d+1):
    print('\t'+str(m),end='')
print(end='\n')
for i in range (a,b+1):
    print(str(i)+'\t',end='')
    for j in range (c,d+1):
        print(str(i*j),end='\t')
    print(end='\n').
