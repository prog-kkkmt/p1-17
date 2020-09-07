/*
Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных целых чисел
(Greatest Common Divisor, GCD). Для этого воспользуйтесь следующими свойствами:*/

unsigned gcd(unsigned a, unsigned b)
{
        if (b == 0)
                return a;
        else
                return gcd (b, a % b);
}
