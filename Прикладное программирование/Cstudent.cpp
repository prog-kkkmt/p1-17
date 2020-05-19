# include <stdio.h>
# include <string.h>
class Cstudent                    //начало определения класса Cstudent
{
private:
    char fio[30];                                        //ФИО студента
    int bd;                                      //год рождения студента
    int num;                                    //номер текущего объекта
    static int count;              //общее количество созданных объектов
public:
    CStudent(char FIO[], int);
                                //прототип конструктора класса Cstudent
    void prn();          //прототип члена(функции prn класса Cstudent
};                                 //конец определения класса Cstudent
CStudent::CStudent(char FIO[] = "Николенко", int BD = 1990) //определение конструктора класса Cstudent
{
    strcpy(fio, FIO);
       //копирование параметра FIO в член(переменную fio класса Cstudent
    bd = BD;
             //присваивание значения параметра BD члену(переменной bd класса
    CStudent
    count++;                         //увеличиваем на 1 количество объектов
    num = count;                        //сохраняем номер текущего объекта
}
int CStudent::count = 0;                  /*обязательная инициализация
                               статического члена вне определения класса и вне
                            всех функций(членов класса и функций программы*/
void CStudent::prn()
                           //определение члена(функции prn класса Cstudent
{
    printf("Студент # %d, %s родился %d;\n Всего
    студентов  %d.\n", num, fio, bd, count);
            //вывод информации о текущем студенте и о количестве студентов
}
int main()
{
    CStudent student1("Иванов Николай", 1995);
    CStudent student2("Лершов Владимир", 1994);
    student1.prn();
    student2.prn();
    return 0;
}