char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *new_str = new char[new_size];
    for (int i = 0; i < ((size > new_size) ? new_size : size); new_str[i] = str[i], i++)
        ;
    delete [] str;
    return new_str;
}
