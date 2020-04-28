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
