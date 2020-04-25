void strcat(char *to, const char *from)
{
    while(*to) to++;
    while(*to++ = *from++);
    *to++ = '\0';
}