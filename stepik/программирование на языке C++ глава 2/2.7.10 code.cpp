
void swap_min(int* m[], unsigned rows, unsigned cols)
{
	int min = m[0][0];
	int str = 0;
	for (int i = 0; i != rows; i++)
		for (int j = 0; j != cols; j++)
			if (m[i][j] < min)
			{
				min = m[i][j]; //минимальное значение 
				str = i; 
			}
	if (str != 0) {
		int* tmp = new int[cols]; //временный одномерный массив для нулевой строки 
		for (int i = 0; i != cols; i++)
			tmp = m[0];
		m[0] = m[str]; //свап строк местами 
		m[str] = tmp;
	}
}
