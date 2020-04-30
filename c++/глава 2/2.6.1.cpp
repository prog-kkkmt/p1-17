/*В этой задаче вам нужно реализовать функцию resize. Функция resize принимает на вход три аргумента: указатель на область памяти, выделенную с помощью оператора new[], размер области (size) и новый размер (new_size). Функция должна выделить память размера new_size, скопировать в нее данные из переданной области памяти, освободить старую область памяти и вернуть выделенную область памяти нового размера со скопированными данными.  */
/*Величко П1-17*/
/*https://stepik.org/lesson/542/step/9?unit=865*/
char *resize(const char *str, unsigned size, unsigned new_size)
{
    char * new_str = new char[new_size];
    for(int i = 0; i < size && i < new_size; ++i)
        new_str[i] = str[i];
    delete[] str;
    return new_str;
}
