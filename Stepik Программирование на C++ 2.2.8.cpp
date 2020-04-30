unsigned gcd(unsigned a, unsigned b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}



