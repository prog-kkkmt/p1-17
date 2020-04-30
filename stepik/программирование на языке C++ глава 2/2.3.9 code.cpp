/*В этой задаче вам нужно реализовать функцию, которая сдвигает содержимое массива влево на заданное число позиций (циклический сдвиг).
На вход функция принимает массив, его размер и величину сдвига. Например, если на вход функции подан массив: int a[] = { 1, 2, 3, 4, 5 }; 
и требуется циклически сдвинуть его влево на 2 позиции, то на выходе мы получим числа в таком порядке: 3, 4, 5, 1, 2.
Обратите внимание, что величина сдвига может быть нулевой, а может быть и больше размера массива, все эти случаи нужно учесть.
Требования к реализации: вам нужно реализовать только функцию циклического сдвига. При этом она не должна вводить или выводить что-либо. 
При решении этой задачи вы можете определять любые вспомогательные функции, если они вам нужны. Реализовывать функцию main не нужно. 
Предполагается, что вам не потребуется дополнительная память, а именно: массивы и стандартные контейнеры. Пользоваться стандартными 
алгоритмами и контейнерами не разрешается, даже если вы с ними знакомы.
Выполнил: Карташов С.П 
Группа: П1-17.
Источник : stepik, программирование на языке с++ Михаил Кринкин, 2.3.9, https://stepik.org/lesson/539/step/9?unit=862
*/

void Shift(int* a, int size, int sh)
{
    if (size < 2) return;
    sh %= size;
    for (int i = 0; i < sh; ++i)
    {
        int l = a[0];
        for (int j = 1; j < size; ++j) a[j - 1] = a[j];
        a[size - 1] = l;
    }
}
