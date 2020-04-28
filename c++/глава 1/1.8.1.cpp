int power(int x, unsigned p) {
    int chislo = 1;
    for(int i = 0; i < p; i++)
        chislo *= x;
    return chislo;
}
