/*Напишите функцию, которая вычисляет длину C-style строки. Учтите, что завершающий нулевой символ считать не нужно. */
/*Величко П1-17*/
/*https://stepik.org/lesson/540/step/6?unit=863*/
unsigned strlen(const char *str)
{
    int i = 0;
    while (str[i]) i++;
    return i;
}
