#include <iostream>
#include "classDescription.h"
///В базе данных хранятся сведения о намеченных событиях (делах, встречах и звонках) и их выполнении.
/**Таблицы: Виды событий (Код вида события, название вида);
События (Код события, Код вида события, название события, время начала, продолжительность, отметка о выполнении).
Определить:
– относительную долю загрузки рабочего дня по приоритетам;
– построить список невыполненных дел в порядке срока давности. **/

/**
Выполнил студент группы П1-17 Карандашев Н.К.
15,05,2020**/

using namespace std;
int main()
{
	size_t _size = 0;
    event *mas = new event[1];
    Append( mas, &_size);
    int k;
    do{
			cin.get();
			cin.get();
			system("cls");
		cout<<"1 - добавить событие"<<endl<<"2 - удалить событие"<<endl<<"3 - вывести"<<endl<<"4 - отсортировать"<<endl<<"5 - запланированные на сегодня мероприятия"<<endl<<"6 - Вывести не посещенные"<<endl<<"7 - О программе"<<endl<<"8 - Изменить"<<endl<<"9 - вывод в файл"<<endl<<"0 - выход"<<endl;
        cin>>k;
        switch(k){
			case 1:system("cls"); Append(mas, &_size); break;
			case 2:system("cls"); int n; cout<<"номер события начиная с 1: "; cin>>n; destroy(mas, &_size, n); break;
			case 3:system("cls"); print(mas, &_size); break;
			case 4:system("cls"); sorted(mas, &_size); break;
			case 5:system("cls"); PrintSob(mas, _size); break;
			case 6:system("cls"); PrintDidNt(mas, _size); break;
			case 7:system("cls"); aboutprograms(); break;
			case 9:system("cls"); PrintFaile(mas, &_size); break;
			case 8:system("cls"); cout<<"номер события который вы жедаете изменить начиная с 1: "; cin>>n; settings(mas[n-1]); break;
        }
    }while(k!=0);
    return 0;
}
