# include <stdio.h>
# include <string.h>
class Cstudent             //начало определения класса Cstudent
{
private:
    char fio[30];                                  //ФИО студента
    int bd;                                //год рождения студента
    int num;                              //номер текущего объекта
    static int count;        //общее количество созданных объектов
    static void prn_count();     //статическая функция(член класса
public:
    CStudent(char FIO[], int);
    //прототип конструктора класса Cstudent

    void prn();           //прототип члена(функции prn класса Cstudent
};
CStudent::CStudent(char FIO[] = "Николенко", int BD =
                       1990)                  //определение конструктора класса Cstudent
{
    strcpy(fio, FIO);
    //копирование параметра FIO в член(переменную fio класса Cstudent
    bd = BD;
    //присваивание значения параметра BD члену(переменной bd класса
    // CStudent
    count++;                              //увеличиваем количество объектов
    num = count;                         //сохраняем номер текущего объекта
}
int CStudent::count = 0;
//обязательная инициализация статического члена
void CStudent::prn()               //определение члена(функции prn класса
Cstudent
{
    printf("Студент # %d, %s родился %d;\n Всего
           студентов  %d.\n", num, fio, bd, count);
           //вывод информации о текущем студенте и о количестве студентов
}
void CStudent::prn_count()
//определение статической члена(функции prn класса Cstudent

{
    printf("Всего %d студентов.\n", count);
    //вывод количества студентов
}
int main()
{
    CStudent student1("Иванов Николай", 1995);
    CStudent student2("Лершов Владимир", 1994);
    student1.prn();
    student2.prn();
    CStudent::prn_count();
    //вызываем статическую функцию, используя имя класса
    return 0;
}
