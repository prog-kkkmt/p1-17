void rotate(int a[], unsigned size, int shift)
{
   for (int i = 0; i < shift; i++) {
       int temp = a[0];
       for (int j = 0; j < size - 1; j++)
           a[j] = a[j + 1];
       a[size - 1] = temp;
   }
}
