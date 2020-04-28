unsigned strlen(const char* str)
{
    unsigned cnt = 0;
    while (*(str + cnt) != 0) ++cnt;

    return cnt;
}