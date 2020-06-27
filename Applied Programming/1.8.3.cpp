/*
Булатников 21.04
Из лекции вы узнали, что использование макросов вместо функций — это зло. Для того, чтобы лучше разобраться, почему так 
непросто написать хороший макрос, и почему макросы лучше не использовать, мы предлагаем вам 
самостоятельно реализовать такую функцию-макрос.

Реализуйте макрос MAX от трёх параметров, который присваивает целочисленной
(int) переменной, переданной в качестве третьего аргумента, наибольшее из значений, 
переданных в первых двух аргументах. Пример вызова макроса:

*/

#define MAX(x, y, r) {int x_ = (x); int y_ = (y); int r_ = ((x_) > (y_) ? (x_) : (y_)); r = r_;}