//https://stepik.org/lesson/540/step/7?unit=863
//Фатеев Д.И.

void strcat(char *to, const char *from)
{
    while(*to != '\0')
    {
        to++;
    }
    while(*from != '\0')
    {
        *to = *from;
        to++;
        from++;
    }
    *to = '\0';
}
