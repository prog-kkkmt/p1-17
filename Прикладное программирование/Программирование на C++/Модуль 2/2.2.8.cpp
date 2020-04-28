// Напишите рекурсивную функцию вычисления наибольшего 
// общего делителя двух положительных целых чисел (Greatest Common Divisor, GCD).

unsigned gcd(unsigned a, unsigned b)
{
    if (a < b)
        return gcd(b, a);

    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}