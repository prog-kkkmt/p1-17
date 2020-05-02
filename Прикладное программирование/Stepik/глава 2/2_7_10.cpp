/*
Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом массиве строку,
содержащую наименьшее среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива.

Требования к реализации: при выполнении этого задания вы можете определять любые вспомогательные функции. 
Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.


Выполнил : Звонарёв Д.А. П1-17 2 мая 2020
Источник : stepik, программирование на языке с++ Михаил Кринкин, 2.7.10, https://stepik.org/lesson/543/step/10?unit=866
*/

#include <iostream>
using namespace std;

void swap_min(int *m[], unsigned rows, unsigned cols)
{
       int min = m[0][0];
       int minR = 0;
       for (int i = 0; i != rows; ++i)
           for (int  j = 0; j != cols; ++j) 
             if( m[i][j]< min)
            {
                min = m[i][j];
                minR = i;
            }
 
        int * buf =  new int [cols];   
      
        for ( int j = 0; j != cols; ++j)  
         {
             buf[j] = m[0][j];
          } 

        copy(m[minR], m[minR] + cols, m[0]);
        copy(buf, buf+ cols, m[minR]);       
             
        delete[] buf; 
        buf = 0;
}
