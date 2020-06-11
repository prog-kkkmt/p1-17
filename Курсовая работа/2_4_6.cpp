unsigned strlen(const char *str)
{
    int a = 0;
    for(; *str != '\0'; str++)
        a++;
    return a;
}
