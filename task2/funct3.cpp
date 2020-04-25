int max(int *a, int *q)
{
	int max = *a;
	for(; a != q; a++)
		if(*a > max)
			max = *a;
	return max;
}