// Вам требуется реализовать функцию конкатенации (склейки) двух C-style строк.

void strcat(char *to, const char *from)
{
    while(*to) to++;
    while(*to++ = *from++);
    *to++ = '\0';
}