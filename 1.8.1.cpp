int power(int x, unsigned p) {
    int a = 1;
    for (int i = 0; i < p; i++)
        a *= x;
    return a;
}
