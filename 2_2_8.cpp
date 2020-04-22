unsigned gcd(unsigned a, unsigned b)
{
    if (a == 0 or b == 0)
        return (a > b) ? a : b;
    return (a > b) ? gcd(a % b, b) : gcd(a, b % a);
}
