int sum(int *a, int *q)
{
	int sum = 0;
	for(; a != q; a++)
		sum += *a;
	return sum;
}
