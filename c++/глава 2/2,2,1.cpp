/*Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных целых чисел (Greatest Common Divisor, GCD).*/
/*Величко П1-17*/
/*https://stepik.org/lesson/538/step/8?unit=861*/
unsigned gcd(unsigned a, unsigned b)
{
        if (b == 0)
                return a;
        else
                return gcd (b, a % b);
}
