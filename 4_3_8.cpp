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
