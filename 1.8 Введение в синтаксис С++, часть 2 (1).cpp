// определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//

int power(int x, unsigned p) {
    int answer = 1, i;
    if (x == 0)
        return 0;
    else if (p == 0)
        return 1;
    else
        for (i = 0; i < p; i++)
            answer = answer * x;
    return answer;
}
