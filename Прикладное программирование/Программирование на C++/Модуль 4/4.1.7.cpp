//Свяжите следующие классы в иерархию наследования
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//https://stepik.org/lesson/552/step/7
//26.04.2020
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
