///Задание: Ваш класс должен печатать (используя std::cout) текстовое представление арифметического выражения. 
///Т.е. для объекта класса Number он должен напечатать число, которое в нем хранится, 
///а для объекта класса BinaryOperation он должен напечатать левый операнд, затем операцию, а затем правый операнд.
///Учтите, что операции + и - имеют меньший приоритет, чем операции * и /, 
///т. е. возможно вам придется печатать дополнительные круглые скобки, чтобы сохранить правильный порядок операций.
///Классы иерархии Expression и абстрактный класс Visitor приведены в комментарии в шаблоне для удобства.
///При проверке задания лишние пробелы или лишние скобки будут игнорироваться,
///т.е. вывод "1+2" эквивалентен выводу "( ( 1 )  +   ( 2 ) )", а вот вывод "1 + 2 * 3" не эквивалентен выводу "((1 + 2) * 3)". 
///Вы можете попытаться минимизировать количество скобок в выводе, но это не требуется.
///Перед выполнением задания внимательно прочитайте содержимое предыдущего степа.
///Требования к реализации: при выполнении задания вы можете заводить любые вспомогательные классы или функции, но не нужно реализовывать функцию main или менять реализацию классов иерархии Expression.
///Источник: Stepic Программирование на языке C++ https://stepik.org/7 от Computer Science Center(CS центр) 
///Глава 4, раздел 5, шаг 10. https://stepik.org/lesson/556/step/10
///Выполнил: Юшаков Н. Р. 25.04.2020.
/*
struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * vistitor) const = 0;
    virtual ~Expression() { }
};

struct Number : Expression
{
    Number(double value);
    double evaluate() const;

    double get_value() const { return value; }

    void visit(Visitor * visitor) const { visitor->visitNumber(this); }

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right);
    ~BinaryOperation();
    double evaluate() const;

    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }

private:
    Expression const * left;
    Expression const * right;
    char op;
};
*/

#include <iostream>

/* Ýòîò êëàññ âàì íóæíî ðåàëèçîâàòü */
struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << bop->get_op();
        bop->get_right()->visit(this);
        std::cout << ")";
    }
};
