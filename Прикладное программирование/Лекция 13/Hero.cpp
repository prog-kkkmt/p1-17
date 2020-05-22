/*Написать класс «герой». Члены класса: имя героя, его возраст. Написать класс «параметры».
Члены класса: сила, защита, скорость. На базе этих двух классов написать класс «воин», включающий в
себя все перечисленные члены/
*/
#include <stdio.h>
#include <string.h>
class Hero                   //начало определения 1(го базового класса Hero
{
protected:
    char name[32];         //защищенная член(переменная name класса Hero
    int age;                //защищенная член(переменная age класса Hero
public:
    Hero()         //определение конструктора класса Hero без параметров
    {
        strcpy(name, "NoName");
        //копирование в член(переменную name текста NoName
        age = 0;                    //присвоить члену(переменной age значения 0
    }
    Hero(char* name, int age)
    //определение конструктора класса Hero с двумя параметрами
    {
        strcpy(this -> name, name);                /*копирование члена(переменной
                           name (this >name) значения параметра name*/
        this ->age = age;
        //присвоить члену(переменной age(this >age) значение параметра age
    }
    void info()                              //определения функции(члена info
    {
        printf("Hero:%s, %d\n", name, age);
        //вывод на экран названия класса и значений членов(переменных name и age
    }
};                                 //конец определения базового класса Hero
class Parametry           //начало определения базового класса Parametry
{
protected:
    int sila;       //защищенная член(переменная sila класса Parametry
    int zashita;
    //защищенная член(переменная zashita класса Parametry
    int skorost;
    //защищенная член(переменная skorost класса Parametry
public:
    Parametry(int _sila = 0, int _zashita = 0,
              int _skorost = 0)
    //конструктор класса Parametry со значениями по умолчаниию
    {
        sila = _sila;
        zashita = _zashita;
        skorost = _skorost;
    }
    void info()          //определение члена(функции info класса Parametry
    {
        printf("Parametry: %d, %d, %d\n", sila, zashita,
               skorost);                /*вывод на экран названия класса и значений
                                   членов(переменных sila, zashita, skorost*/
    }
};                                   //конец определения класса Parametry
class Warrior : public Hero, Parametry
//начало определ. класса Warrior наследника классов Hero, Parametry
{
public:
    /*определение конструктора класса Warrior инициализацией
    «родительских» конструкторов классов Hero и Parametry*/
    Warrior(char* _name, int _age, int _sila, int _zashita,
            int _skorost): Hero(_name, _age), Parametry(_sila,
                        _zashita, _skorost)
    {                                                                          }
    void info()              //определение члена(функции info класса Warrior
    {
        printf("Warrior:\n");
        //вывод на экран названия класса Warrior
        Hero::info();                  //вызов функции(члена info класса Hero
        Parametry::info();
        //вызов функции(члена info класса Parametry
    }
};                                      //конец определения класса Warrior
int main()
{
    Warrior w("Ivan", 30, 100, 300, 15);
    w.info();
    return 0;
}

