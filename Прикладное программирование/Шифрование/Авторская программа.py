'Программу разработал Бобнев Алексей П1-17'
'30.05.2020'
'Симуляция пароля'
print('1 - Установка пароля')
print('2 - Введите пароль')
print('3 - Пароль не зашифроманный и зашифрованный')
print('0 - Выход')

menu = int(input())
up = '0'
p = '0'
p1 = '0'

while ((menu == 1) | (menu == 2) | (menu == 3)):
   if menu == 1:
      ustanovka_parol = input()
      p = ustanovka_parol
      up = ustanovka_parol + '1'
      p1 = up

   if menu == 2:
      parol = input()
      parol = parol + '1'
      if parol != up:
         print('Нет')
      else: print('Вход')

   if menu == 3:
      print('Не зашифрованный пароль:', p)
      print('Зашифрованный пароль:', p1)
   
   print('1 - Установка пароля')
   print('2 - Введите пароль')
   print('3 - Пароль введенный и зашифрованный')
   print('0 - Выход')
   menu = int(input())
