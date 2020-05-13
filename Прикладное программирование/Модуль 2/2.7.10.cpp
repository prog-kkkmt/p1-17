/*Ğåàëèçóéòå ôóíêöèş swap_min, êîòîğàÿ ïğèíèìàåò íà âõîä äâóìåğíûé ìàññèâ öåëûõ ÷èñåë, èùåò â ıòîì
ìàññèâå ñòğîêó, ñîäåğæàùóş íàèìåíüøåå ñğåäè âñåõ ıëåìåíòîâ ìàññèâà çíà÷åíèå, è ìåíÿåò ıòó ñòğîêó
ìåñòàìè ñ ïåğâîé ñòğîêîé ìàññèâà.
Âûïîëíèë: Ñàïîëåòîâà Àíàñòàñèÿ
Èñòî÷íèê: Stepik Computer Science Center (CS öåíòğ)
Ïğîãğàììèğîâàíèå íà ÿçûêå C++
2.7.10 https://stepik.org/lesson/543/step/10
13.05.2020
*/
void swap_min(int *m[], unsigned rows, unsigned cols)
{
    unsigned int m_i = 0;
    int min =m[0][0];
    for(unsigned i = 0; i != rows; i++)
         for(unsigned j = 0; j != cols; j++)
             if(min > m[i][j]){
                 m_i = i;
                 min = m[i][j];
             }
    int * t = m[m_i];
    m[m_i] = m[0];
    m[0] = t;

}
