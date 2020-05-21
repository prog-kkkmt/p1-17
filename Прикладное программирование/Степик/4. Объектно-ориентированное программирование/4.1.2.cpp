/*
Закрепление материала.
Выполнил Бобнев Алексей
Ссылка: https://stepik.org/lesson/552/step/2?unit=875
21.05.2020
*/

#include <iostream>

using namespace std;

struct Person
{
    string name() const {return name_;}
    int age() const {return age_;}
    private:
        string name_;
        int age_;
};

struct Student : Person
{
    string universety() const {return uni_;}
    private:
        string uni_;
};

int main()
{
    return 0;
}
