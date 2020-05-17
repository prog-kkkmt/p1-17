// В этой задаче вам нужно реализовать функцию, которая сдвигает содержимое массива 
// влево на заданное число позиций (циклический сдвиг).
//Выполнил: Богомолов Максим П1-17
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//2.3.9 https://stepik.org/lesson/539/step/9
//25.04.2020
void move(int a[], unsigned size)
{
  int buff;
  for (int i = 0; i < size - 1; i++) {
    buff = a[i];
    a[i] = a[i + 1];
    a[i + 1] = buff;
  }
}

void rotate(int a[], unsigned size, int shift)
{
  if (shift >= size)
    shift = shift % size;
  
  for (int i = 0; i < shift; i++) {
      move(a, size);
  }
}
