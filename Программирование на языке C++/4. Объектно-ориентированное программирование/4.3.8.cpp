///Задание: В этом задании вам предлагается разработать иерархию классов Expression для представления арифметических выражений. 
///Конкретнее, вам нужно определить три класса: Expression — базовый класс иерархии, 
///Number — для представления чисел и BinaryOperation — класс описывающий бинарную операцию (+, -, * или /).
///Класс Number должен хранить значение типа double.
///Класс BinaryOperation должен хранить указатель на левый и правый операнды, которые сами являются арифметическими выражениями, 
///а также тип операции (+, -, * или /), которую нужно над ними произвести.
///Во всех классах должен быть метод evaluate, который возвращает значение типа double — 
///значение соответствующего арифметического выражения, например, значение экземпляра типа Number — это число, которое он хранит, 
///а если у вас есть объект BinaryOperation с операцией +, то нужно вычислить значения левого и правого операнда и вернуть их сумму.
///В данном задании вам нужно расставить ключевое слово virtual там, где это необходимо, определить метод evaluate там, 
///где его не хватает, а также реализовать деструкторы, там где они нужны.
///При выполнении этого задания учтите, что при уничтожении объекта BinaryOperation он отвечает за уничтожение левого и правого операндов 
///(гарантируется, что они выделены в динамической памяти).
///Требования к реализации: при выполнении этого задания не нужно вводить или выводить что-либо. 
///Вы можете заводить любые вспомогательные функции, методы или классы, но не нужно реализовывать функцию main.
///Источник: Stepic Программирование на языке C++ https://stepik.org/7 от Computer Science Center(CS центр) 
///Глава 4, раздел 3, шаг 8. https://stepik.org/lesson/554/step/8
///Выполнил: Юшаков Н. Р. 25.04.2020.
struct Expression
{
    virtual ~Expression() {}
    virtual double evaluate() const = 0;
};

struct Number : Expression
{
    virtual ~Number() {}
    Number(double value)
        : value(value)
    {}

    double evaluate() const {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    ~BinaryOperation() {
        delete left;
        delete right;
    }

    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }

    double evaluate() const {
        switch (op) {
            case '+': return left->evaluate() + right->evaluate(); break;
            case '-': return left->evaluate() - right->evaluate(); break;
            case '*': return left->evaluate() * right->evaluate(); break;
            case '/': return left->evaluate() / right->evaluate(); break;
        }
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};
