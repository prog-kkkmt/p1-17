// Вам требуется реализовать функцию конкатенации (склейки) двух C-style строк.
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//2.4.7 https://stepik.org/lesson/540/step/7
//25.04.2020
void strcat(char *to, const char *from)
{
    while(*to) to++;
    while(*to++ = *from++);
    *to++ = '\0';
}
