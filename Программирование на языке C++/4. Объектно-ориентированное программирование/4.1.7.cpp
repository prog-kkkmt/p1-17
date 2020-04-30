///Задание: Свяжите следующие классы в иерархию наследования: Character (Персонаж), LongRange (Персонаж дальнего действия), 
///Wizard (Маг), SwordsMan (Мечник), Archer (Лучник).
///Обратите внимание на методы, объявленные в классах — они приведены в качестве описания интерфейса, которым должны обладать классы. 
///Не изменяйте объявлений методов — они даны как подсказка, просто добавьте наследование в определения классов.
///Источник: Stepic Программирование на языке C++ https://stepik.org/7 от Computer Science Center(CS центр) 
///Глава 4, раздел 1, шаг 7. https://stepik.org/lesson/552/step/7
///Выполнил: Юшаков Н. Р. 24.04.2020.
#include <string> // std::string

struct Character
{
    std::string const & name() const;
    unsigned health() const;
};

struct LongRange : Character
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;
};

struct SwordsMan : Character
{
    std::string const & name() const;
    unsigned health() const;

    unsigned strength() const;
};

struct Wizard : LongRange
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;

    unsigned mana() const;
};

struct Archer : LongRange
{
    std::string const & name() const;
    unsigned health() const;

    unsigned range() const;

    unsigned accuracy() const;
};
