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
