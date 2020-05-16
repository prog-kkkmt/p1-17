import re

stra = input("Введите строку для поиска: ")
reg = input("\nВведите регулярное выражение(без //, в формате [asd]+): ")

regexp = re.compile(reg)

match = regexp.match(stra)

print("\nПервое совпадение: '" + match.group(0) + "' в позициях {" + str(match.start(0)) + ', ' + str(match.end(0)) + "}")