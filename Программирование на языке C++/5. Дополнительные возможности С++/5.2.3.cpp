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

    Rational & operator+=(const Rational & a) {
        this->add(a);
        return *this;
    }

    Rational & operator+=(int num) {
        this->add(Rational(num));
        return *this;
    }

    Rational & operator-=(const Rational & a) {
        this->sub(a);
        return *this;
    }

    Rational & operator-=(int num) {
        this->sub(Rational(num));
        return *this;
    }

    Rational & operator*=(const Rational & a) {
        this->mul(a);
        return *this;
    }

    Rational & operator*=(int num) {
        this->mul(Rational(num));
        return *this;
    }

    Rational & operator/=(const Rational & a) {
        this->div(a);
        return *this;
    }

    Rational & operator/=(int num) {
        this->div(Rational(num));
        return *this;
    }

    Rational operator-() const { Rational r(this->numerator_, this->denominator_); r.neg(); return r; }

    Rational operator+() const { Rational r(this->numerator_, this->denominator_); return r; }

private:
    int numerator_;
    int denominator_;
};
