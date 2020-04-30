// """
// Напишите функцию power, реализующую возведение целого числа в неотрицательную целую степень. 
// Функция power должна принимать на вход два целых числа и возвращать целое число (смотрите шаблон кода). 
// При выполнении задания учтите, что 
// функция обязательно должна называться power, функция ничего не должна читать со входа или выводить.

// """

// определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//
//Выполнил: Пищулин Игорь
//Источник: Stepik Computer Science Center (CS центр)
//Программирование на языке C++
//1.8.4 https://stepik.org/lesson/13377/step/4
//25.04.2020
int power(int x, unsigned p) {
    int answer = 1;
    for (int i = 0; i < p; i++)
        answer *= x;
    return answer;
}
