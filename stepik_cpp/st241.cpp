//https://stepik.org/lesson/540/step/6?unit=863
//Фатеев Д.И.

unsigned strlen(const char *str)
{
    int k = 0;
    while(*str != '\0')
    {
        k++;
        str++;
    }
    return k;
}
