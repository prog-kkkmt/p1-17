//https://stepik.org/lesson/539/step/9?unit=862
//Фатеев Д.И.

void rotate(int a[], unsigned size, int shift)
{
    for(int i = 0; i < shift; i++)
    {
        int temp = a[0];
		for (int i = 0; i < size - 1; i++)
        {
			a[i] = a[i + 1];
        }
		a[size - 1] = temp;
    }
}
