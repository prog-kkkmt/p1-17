/*Напишите функцию поиска первого вхождения шаблона в текст.*/
/*Величко П1-17*/
/*https://stepik.org/lesson/540/step/8?unit=863*/
int strstr(const char *text, const char *pattern)
{
    if (!*pattern)
		return 0;
	for (int i = 0; * (text + i); i++)
		for (int j = 0; *(text + i + j) == *(pattern + j) || (!*(pattern + j)); j++)
			if (!*(pattern + j))
				return i;
	return -1;
}
