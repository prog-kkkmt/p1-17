## 	Python regexp test	
##	Developer: Pishchulin Igor 
## 	16.05.2020
##

import re # подключаем библиотеку

stra = input("Введите строку для поиска: ")
reg = input("\nВведите регулярное выражение(без //, в формате [asd]+): ")

regexp = re.compile(reg) # создаем объект выражение

match = regexp.match(stra) #ищем соответствие c нулевой позиции

print("\nПервое совпадение: '" + match.group(0) + "' в позициях {" + str(match.start(0)) + ', ' + str(match.end(0)) + "}")