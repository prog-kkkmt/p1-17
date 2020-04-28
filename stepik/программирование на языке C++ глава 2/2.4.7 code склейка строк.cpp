#include <stdio.h>

char* _strcat(char* dst, const char* src)
{
	char* p = dst;
	for (; *p; p++);
	for (; (*p++ = *src++); );
	return dst;
}

int main()
{
	char s[] = "everyone!";
	char buf[20] = "Hi, ";
	printf("%s", _strcat(buf, s));

	return 0;
}
