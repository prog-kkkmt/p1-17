struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);

    Rational operator-() const;
    Rational operator+() const;

public:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);

bool operator ==(Rational const &left, Rational const &right)
{
	return left.numerator_*right.denominator_ == right.numerator_*left.denominator_;
}

bool operator !=(Rational const &left, Rational const &right)
{
	return !(left == right);
}

bool operator <(Rational const &left, Rational const &right)
{
	return left.numerator_*right.denominator_ < right.numerator_*left.denominator_;
}

bool operator >(Rational const &left, Rational const &right)
{
	return right < left;
}

bool operator <=(Rational const &left, Rational const &right)
{
	return !(left > right);
}

bool operator >=(Rational const &left, Rational const &right)
{
	return !(left < right);
}
