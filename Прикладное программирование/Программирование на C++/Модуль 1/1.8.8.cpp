// """
// Реализуйте макрос MAX от трёх параметров, который присваивает целочисленной (int) переменной, 
// переданной в качестве третьего аргумента, наибольшее из значений, переданных в первых двух аргументах.

// """

#define MAX(x, y, r) ({typeof(x) _x = x; typeof(y) _y = y; \
      (r) = ( _x > _y ? _x : _y);})