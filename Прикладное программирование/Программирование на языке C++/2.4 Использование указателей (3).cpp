int strstr(const char *text, const char *pattern)
{
    int index = 0;
    if (*pattern == '\0')
        return 0;
    while (*text != '\0')
    {
        if (*text == *pattern)
        {
            const char* newPattern = pattern;
            const char* newText = text;
            while (*newText == *newPattern && *newPattern != '\0')
            {
                newText++;
                newPattern++;
            }
            if (*newPattern == '\0')
                return index;
        }
        text++;
        index++;
    }
    return -1;
}
