///Задание: В этой задаче вам нужно реализовать функцию, которая сдвигает содержимое массива влево на заданное число позиций (циклический сдвиг).
///На вход функция принимает массив, его размер и величину сдвига. Например, если на вход функции подан массив: 
///int a[] = { 1, 2, 3, 4, 5 }; и требуется циклически сдвинуть его влево на 2 позиции, 
///то на выходе мы получим числа в таком порядке: 3, 4, 5, 1, 2.
///Обратите внимание, что величина сдвига может быть нулевой, а может быть и больше размера массива, все эти случаи нужно учесть.
///Требования к реализации: вам нужно реализовать только функцию циклического сдвига. 
///При этом она не должна вводить или выводить что-либо. При решении этой задачи вы можете определять любые вспомогательные функции, 
///если они вам нужны. Реализовывать функцию main не нужно. Предполагается, что вам не потребуется дополнительная память, 
///а именно: массивы и стандартные контейнеры. Пользоваться стандартными алгоритмами и контейнерами не разрешается, 
///даже если вы с ними знакомы. Рекомендация: перед тем, как начать кодировать решение этой задачи, продумайте алгоритм, 
///который вы будете использовать. В данной задаче не проверяется эффективность этого алгоритма (в разумных пределах).
///Подсказка: вам может потребоваться оператор % для вычисления остатка. 
///Наиболее простая реализация этой функции сдвигает массив на один элемент за проход. 
///Наиболее простая реализация несколько раз использует функцию, которая переставляет элементы массива в обратном порядке.
///Источник: Stepic Программирование на языке C++ https://stepik.org/7 от Computer Science Center(CS центр) 
///Глава 2, раздел 3, шаг 12. https://stepik.org/lesson/539/step/9
///Выполнил: Юшаков Н. Р. 22.04.2020.
void rotate(int a[], unsigned size, int shift)
{
   shift %= size;
   for (int i = 0; i < shift; i++) {
       int temp = a[0];
       for (int j = 0; j < size - 1; j++)
           a[j] = a[j + 1];
       a[size - 1] = temp;
   }
}
