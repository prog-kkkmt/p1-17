// Напишите функцию, которая вычисляет длину C-style строки.
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//2.4.6 https://stepik.org/lesson/540/step/6
//25.04.2020
unsigned strlen(const char *str)
{
  unsigned i = 0;
  while(*str++) i++;
  return i;
}
