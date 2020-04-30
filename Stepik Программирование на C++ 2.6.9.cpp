char *resize(const char *str, unsigned size, unsigned new_size)
{
	char *new_memory = new char[new_size];
    int min_size;
    if (size < new_size)
        min_size = size;
    else
        min_size = new_size;
    for (int i = 0; i < min_size; i++)
        new_memory[i] = str[i];
    delete[] str;
    return new_memory;
}
