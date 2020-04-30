/*Напишите функцию поиска первого вхождения шаблона в текст. В качестве первого параметра функция принимает текст (C-style строка), в 
которой нужно искать шаблон. В качестве второго параметра строку-шаблон (C-style строка), которую нужно найти. Функция возвращает позицию 
первого вхождения строки-шаблона, если он присутствует в строке (помните, что в C++ принято считать с 0), и -1, если шаблона в тексте нет.
Учтите, что пустой шаблон (строка длины 0) можно найти в любом месте текста.
Требования к реализации: при выполнении данного задания вы можете определять любые вспомогательные функции, если они вам нужны. Вводить 
или выводить что-либо не нужно. Реализовывать функцию main не нужно.

Выполнил : Звонарёв Д.А. П1-17 21 апреля 2020
Источник : stepik, программирование на языке с++ Михаил Кринкин, 2.4.8, https://stepik.org/lesson/540/step/8?unit=863
*/
int strstr(const char *text, const char *pattern)
{   
    int j = 0;
    
    if (*pattern == '\0') 
        return 0;
        
    for(int i = 0; text[i] != '\0'; i++)
{
    while(text[i+j] != '\0' && pattern[j] == text[i+j]) 
        j++;
    if(pattern[j] == '\0') 
        return i;
    j = 0;
} 
    return -1; 
}
