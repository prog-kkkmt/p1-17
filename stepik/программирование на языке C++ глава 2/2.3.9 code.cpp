void Shift(int* a, int size, int sh)
{
    if (size < 2) return;
    sh %= size;
    for (int i = 0; i < sh; ++i)
    {
        int l = a[0];
        for (int j = 1; j < size; ++j) a[j - 1] = a[j];
        a[size - 1] = l;
    }
}
