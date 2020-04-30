/*Очень часто для работы со строками нам нужно сначала вычислить длину строки. Для C-style строк длина нигде явно не хранится, но её 
можно вычислить. Напишите функцию, которая вычисляет длину C-style строки. Учтите, что завершающий нулевой символ считать не нужно.
Требования к реализации: при выполнении этого задания вы можете создавать любые вспомогательные функции. Вводить или выводить что-либо 
не нужно. Реализовывать функцию main не нужно.

Выполнил : Звонарёв Д.А. П1-17 21 апреля 2020
Источник : stepik, программирование на языке с++ Михаил Кринкин, 2.4.6, https://stepik.org/lesson/540/step/6?unit=863
*/
unsigned strlen(const char *str)
{
    int i = 0;
    while (str[i]) i++;
    return i;
}
