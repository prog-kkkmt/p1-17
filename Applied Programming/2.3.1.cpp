void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void reverse(int* a, unsigned size)
{
    for (int i = 0; i < size/2; ++i)
    {
        swap(a[i],a[size-1-i]);
    }
}

void rotate(int a[], unsigned size, int shift)
{
    if (shift > size)
    {
        shift %= size;
    }

    reverse(a, shift);
    reverse(a + shift, size - shift);
    reverse(a, size);
}
