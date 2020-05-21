/*
Закрепление материала.
Выполнил Бобнев Алексей
Ссылка: https://stepik.org/lesson/553/step/3?unit=876
21.05.2020
*/

#include <iostream>

using namespace std;

struct Vector2D
{
    Vector2D(double x, double y) : x(x), y(y) {}

    Vector2D mult(double d) const
    {
        return Vector2D(x * d, y * d);
    }

    double mult(Vector2D const & p)
    {
        return x * p.x + y * p.y;
    }

    double x, y;

};

int main()
{
    Vector2D p(1, 2);
    Vector2D q = p.mult(10);
    double r = p.mult(q);
    return 0;
}
