struct Expression
{
    virtual ~Expression() {}
    virtual double evaluate() const = 0;
};

struct Number : Expression {
    Number(double value) : value(value) {}
    virtual double evaluate() const override {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }
     double evaluate () const {
        switch (op) {
            case '+': return left->evaluate() + right->evaluate();
            case '-': return left->evaluate() - right->evaluate();
            case '*': return left->evaluate() * right->evaluate();
            case '/': return left->evaluate() / right->evaluate();
        }
        return 0.0;
    }

    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};
