// Напишите рекурсивную функцию вычисления наибольшего 
// общего делителя двух положительных целых чисел (Greatest Common Divisor, GCD).
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//2.2.8 https://stepik.org/lesson/538/step/8
//25.04.2020
unsigned gcd(unsigned a, unsigned b)
{
    if (a < b)
        return gcd(b, a);

    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
