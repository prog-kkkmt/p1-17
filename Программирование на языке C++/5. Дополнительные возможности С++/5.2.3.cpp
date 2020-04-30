///Задание: Вам дан класс Rational, который описывает рациональное число. В нем определены методы add, sub, mul и div, 
///которые прибавляют к нему число, отнимают число, умножают на число и делят на число соответственно. 
///Кроме того в нем определен метод neg, который меняет знак на противоположный.
///Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, 
///чтобы они могли принимать в качестве аргументов и объекты типа Rational и целые числа. 
///Кроме того вам необходимо определить операторы унарного минуса и плюса для класса Rational.
///Требования к реализации: ваш код не должен вводить или вводить что-либо, реализовывать функцию main не нужно. 
///Кроме того, нельзя (это совершенно не нужно) использовать динамическую память или подключать какие-либо библиотеки.
///Источник: Stepic Программирование на языке C++ https://stepik.org/7 от Computer Science Center(CS центр) 
///Глава 5, раздел 2, шаг 3. https://stepik.org/lesson/559/step/3
///Выполнил: Юшаков Н. Р. 29.04.2020.
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
