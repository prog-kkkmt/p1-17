/*Транспонирование матрицы*/
/*Величко П1-17*/
/*https://stepik.org/lesson/543/step/9?unit=866*/
int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
   int** matr = new int*[cols]; 
   for (int i=0; i<cols; ++i){
       matr[i] = new int [rows];
       for(int j=0;j<rows;j++)
           matr[i][j]=m[j][i];
}
   return matr;
}
