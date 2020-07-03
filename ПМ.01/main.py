#=======================================
#ПМ.01
#Билет 17.
#Выполнил Бобнв Алексей П1-17
#=======================================
class Student:
    def __init__(self, kod_pacient, kod_doctor, Familia_doc, Specializac, Familia_p, Adress, kod_diagnoz, name, lechenie):
        self.kod_pacient = kod_pacient
        self.kod_doctor = kod_doctor
        self.Familia_doc = Familia_doc
        self.Specializac = Specializac
        self.Familia_p = Familia_p
        self.Adress = Adress
        self.kod_diagnoz = kod_diagnoz
        self.name = name
        self.lechenie = lechenie
        
    def dobavlenie_pacientov(self):#Добавление в файл
        z = open('Пациенты.txt', 'a', encoding = 'utf-8')
        z1 = self.kod_pacient + " " + self.Familia_p  + " " + self.Adress + '\n'
        z.write(z1)
        z.close()

    def dobavlenie_doctors(self):#Добавление в файл
        z = open('Врачи.txt', 'a', encoding = 'utf-8')
        z1 = self.kod_doctor + " " + self.Familia_doc + " " + self.Specializac + '\n'
        z.write(z1)
        z.close()

    def dobavlenie_priem(self):#Добавление в файл
        z = open('Приемы.txt', 'a', encoding = 'utf-8')
        z1 = self.Familia_doc + ' ' + self.Familia_p + '\n'
        z.write(z1)
        z.close()

    def dobavlenie_d(self):#Добавление в файл
        z = open('Диагнозы.txt', 'a', encoding = 'utf-8')
        z1 = self.kod_diagnoz + " " + self.name + " " + self.lechenie + '\n'
        z.write(z1)
        z.close()

    def kol(self):
        z = open('Приемы.txt', 'r', encoding = 'utf-8')
        z1 = z.read()
        z2 = z1.split()
        z.close()
        for i in range (0, len(z2)):
            k = 0
            if ((i % 2) != 0):
                for j in range (0, len(z2)):
                    if ((i % 2) != 0):
                        if (z2[i] == z2[j]):
                            k = k + 1
            if ((i % 2) != 0):
                print(z2[i], k)

    def ot(self):
        z = open('Врачи.txt', 'r', encoding = 'utf-8')#Чтение из файла
        z1 = z.read()
        z2 = z1.split()
        z.close()
        for i in range (0, len(z2)):
            k = 0
            if ((i % 2) != 0):
                for j in range (0, len(z2)):
                    if ((i % 2) != 0):
                        if (z2[i] == z2[j]):
                            k = k + 1
            if ((i % 2) != 0):
                print(z2[i], k / (len(z2) / 2) * 100)


Familia_doc = input()#Врач
kod_doctor = input()
Specializac = input()


Familia_p = input()#Пациент
kod_pacient = input()
Adress = input()

kod_diagnoz = input()#Диагноз
name = input()
lechenie = input()

p1 = Student(kod_pacient, kod_doctor, Familia_doc, Specializac, Familia_p, Adress, kod_diagnoz, name, lechenie)
p1.dobavlenie_doctors()
p1.dobavlenie_pacientov()
p1.dobavlenie_priem()
p1.dobavlenie_d()
p1.kol()
p1.ot()
