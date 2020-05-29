#include <iostream>
#include "classDescription.h"
#include "StructTwochapters.h"


/**
в данной версию программы добавлена печать в html формвте

16,05,2020**/

using namespace std;
int main()
{
	setlocale(0,"");
	size_t _size = 0, m = 0;
    event *mas = new event[0];
    CodeSystem *code = new CodeSystem[0];
    //Append( mas, &_size);
	int k;
    do{
		cout<<"1-đŕáîňŕ ń ńîáűňč˙ěč\n"<<"2-đŕáîňŕ ń ęîäŕěč\n"<<"0 - âűőîä\n";
		cin>>k;
		if(k==1){
			system("cls");
			cout<<"1 - äîáŕâčňü ńîáűňčĺ"<<endl<<"2 - óäŕëčňü ńîáűňčĺ"<<endl<<"3 - âűâĺńňč"<<endl<<"4 - îňńîđňčđîâŕňü"<<endl<<"5 - çŕďëŕíčđîâŕííűĺ íŕ ńĺăîäí˙ ěĺđîďđč˙ňč˙"<<endl<<"6 - Âűâĺńňč íĺ ďîńĺůĺííűĺ"<<endl<<"7 - Î ďđîăđŕěěĺ"<<endl<<"8 - Čçěĺíčňü"<<endl<<"9 - âűâîä â ôŕéë"<<endl<<"10 - Вывод в HTML таблицу"<<endl<<"0 - âűőîä"<<endl;
			cout<<endl;
			cin>>k;
			switch(k){
				case 1:system("cls"); Append(mas, &_size); break;
				case 2:system("cls"); int n; cout<<"íîěĺđ ńîáűňč˙ íŕ÷číŕ˙ ń 1: "; cin>>n; destroy(mas, &_size, n); break;
				case 3:system("cls"); print(mas, &_size); break;
				case 4:system("cls"); sorted(mas, &_size); break;
				case 5:system("cls"); PrintSob(mas, _size); break;
				case 6:system("cls"); PrintDidNt(mas, _size); break;
				case 7:system("cls"); aboutprograms(); break;
				case 9:system("cls"); PrintFaile(mas, &_size); break;
				case 10:system("cls"); PrintAllWebCode(mas, &_size); break;
				case 8:system("cls"); cout<<"íîěĺđ ńîáűňč˙ ęîňîđűé âű ćĺäŕĺňĺ čçěĺíčňü íŕ÷číŕ˙ ń 1: "; cin>>n; settings(mas[n-1]); break;
			}
			k=-1;
		}
		else if (k==2){
            cout<<"1 - äîáŕâčňü ęîä\n2 - óäŕëčňü ęîä \n3 - čçěĺíčňü ęîä\n4 - âűâĺńňč âńĺ ęîäű\n5 - âűâĺńňč âńĺ â ôŕéë\n6-вывести все в html формат: ";
            cout<<endl;
			cin>>k;
            switch(k){
				case 1:system("cls"); Append(code, &m); break;
				case 2:system("cls"); int n; cout<<"íîěĺđ ęîäŕ íŕ÷číŕ˙ ń 1: "; cin>>n; destroy(code, &m, n); break;
				case 3:system("cls"); cout<<"íîěĺđ ęîäŕ ęîňîđűé âű ćĺäŕĺňĺ čçěĺíčňü: "; cin>>n; settings(code[n-1]); break;
				case 4:system("cls"); PrintAll(mas, &_size, code, &m); break;
				case 5:system("cls"); PrintAllFaile(mas, &_size, code, &m); break;
				case 6:system("cls"); PrintAllWebCode(code, &m); break;
			}
			k=-1;
		}
        cin.get();
		cin.get();
    }while(k!=0);
    return 0;

}
