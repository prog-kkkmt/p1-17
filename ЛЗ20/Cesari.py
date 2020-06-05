print("Введите строку")
s=input()
print("Введите шаг")
a=int(input())
result = ""
for char in s:
    result += chr(ord(char) + a)
print("Резудьтат " + result)
