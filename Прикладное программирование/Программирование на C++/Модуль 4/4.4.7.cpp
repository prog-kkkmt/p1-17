// Вам требуется реализовать функцию, которая принимает на вход два указателя на базовый класс 
// Expression, и возвращает true, если оба указателя указывают на самом деле на объекты одного 
// и того же класса, и false в противном случае
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//https://stepik.org/lesson/555/step/7
//26.04.2020
bool check_equals(Expression const *left, Expression const *right)
{
    return *((int*)left) == *((int*)right);
}
