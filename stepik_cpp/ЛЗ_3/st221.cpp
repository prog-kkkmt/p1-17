/*Напишите рекурсивную функцию вычисления наибольшего общего делителя двух положительных целых чисел (Greatest Common Divisor, GCD). 
Для этого воспользуйтесь следующими свойствами:

GCD(a, b) = GCD(b, a mod b)
GCD(a, b) = GCD(b,a mod b)
GCD(0, a) = GCD(0,a)=a
GCD(a, b) = GCD(b, a)GCD(a,b)=GCD(b,a)
*/
//https://stepik.org/lesson/538/step/8?unit=861
//Фатеев Д.И.

unsigned gcd(unsigned a, unsigned b)
{
    if(a>b)
        return gcd( a-b,  b);
    else if(a<b)
        return gcd( a,  b-a);
    else return a;
}
