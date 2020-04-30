bool check_equals(Expression const *left, Expression const *right)
{
    int* lol = *((int**)left);
    int* kek = *((int**)right);
    return lol == kek;
}
