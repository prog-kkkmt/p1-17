// Напишите функцию, которая вычисляет длину C-style строки.

unsigned strlen(const char *str)
{
  unsigned i = 0;
  while(*str++) i++;
  return i;
}