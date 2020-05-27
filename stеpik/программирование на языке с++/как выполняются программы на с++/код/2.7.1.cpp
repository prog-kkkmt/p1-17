int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** mass = new int * [cols];
    mass[0] = new int[rows * cols];
    for(int i = 1; i != cols; i++)
        mass[i] = mass[i - 1] + rows;
  for(int k = 0; k < cols; k++)
      for(int q = 0; q < rows; q++)
          mass[k][q] = m[q][k];
    return mass;
}

