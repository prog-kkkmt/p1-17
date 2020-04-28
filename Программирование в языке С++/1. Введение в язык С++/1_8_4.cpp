// îïðåäåëèòå òîëüêî ôóíêöèþ power, ãäå
//    x - ÷èñëî, êîòîðîå íóæíî âîçâåñòè â ñòåïåíü
//    p - ñòåïåíü, â êîòîðóþ íóæíî âîçâåñòè x


int power(int x, unsigned p) {
    int answer = 1;
    int i;
    for(i = 0; i < p; i++)
        answer *= x;
    return answer;
}
