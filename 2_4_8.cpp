int strstr(const char *text, const char *pattern)
{
    if (*pattern == '\0')
        return 0;
    else if (*text == '\0')
        return -1;
    for (int k = 0;*text != '\0'; text++, k++) {
        const char* start = pattern;
        const char* prob = text;
        if (*text == *start)
            for (; *prob == *start && *start != '\0'; prob++, start++)
                ;
        if (*start == '\0') {
            return k;
        }

    }
    return -1;
}
