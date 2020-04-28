/*�������� ����������� ������� ���������� ����������� ������ �������� ���� ������������� ����� ����� (Greatest Common Divisor, GCD). ��� ����� �������������� ���������� ����������:

GCD(a, b) = GCD(b, a \bmod b)GCD(a,b)=GCD(b,amodb)
GCD(0, a) = aGCD(0,a)=a
GCD(a, b) = GCD(b, a)GCD(a,b)=GCD(b,a)*/

unsigned gcd(unsigned a, unsigned b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
