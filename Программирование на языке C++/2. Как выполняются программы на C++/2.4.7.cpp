void strcat(char *to, const char *from)
{
    for (; *to != '\0'; to++)
        ;
    for (; *from != '\0'; *to = *from, to++, from++)
        ;
    *to = '\0';
}
