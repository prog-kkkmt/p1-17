void move(int a[], unsigned size)
{
  int buff;
  for (int i = 0; i < size - 1; i++) {
    buff = a[i];
    a[i] = a[i + 1];
    a[i + 1] = buff;
  }
}

void rotate(int a[], unsigned size, int shift)
{
  if (shift >= size)
    shift = shift % size;
  
  for (int i = 0; i < shift; i++) {
      move(a, size);
  }
}