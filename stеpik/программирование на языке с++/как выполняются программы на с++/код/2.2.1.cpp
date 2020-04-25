//ЛЗ 3 2404.2020
//Напишите рекурсивную функцию вычисления
//наибольшего общего делителя двух положительных целых чисел

unsigned gcd (unsigned a, unsigned b) {
    if (b==0)
        return a;
    else
        return gcd (b, a%b);
}
