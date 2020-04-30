/*Вам требуется реализовать функцию конкатенации (склейки) двух C-style строк. */
/*Величко П1-17*/
/*https://stepik.org/lesson/540/step/7?auth=registration&unit=863*/
void strcat(char *to, const char *from)
{
    while (*to)
    {
        to++;
    }
    while(*from)
    {
        *to = *from;
        to++;
        from++;
    }
    *to = '\0';
}
