#include <iostream>

///Цель написать программу показывающую разницу параметров доступа
using namespace std;
class student{
	public:
student(){///Конструктор по умолдчанию
	setlocale(0,"");
	cout<<"Введите имя ";
	cin>>name;
	cout<<"Введите Отчество ";
	cin>>lastname;
	cout<<"Введите Фамилию ";
	cin>>secondname;
}
student(string _temp, string _tempn, string _Temp){///Конструктор с Параметром
	name=_temp;
	lastname = _tempn;
	secondname = _Temp;
}

///Деструктор по умолчанию

void print(){
    cout<<name<<"\t"<<lastname<<"\t"<<secondname<<endl;
}
private:
	string name;///Закрытая переменная для всех
protected:
	string lastname;///Открытая только для наследования
public:
	string secondname;///полностью открытая переменная
};

int main()
{
	student k;
	///k.name = "Ira"; - Нигде не сработает
	///k.lastname = "Ira"; - Сработает только у классов наследования
	///k.secondname = "Ira"; - сработает

	///Стоит сказать что для Frend параметра доступа не играют никакой роли. им доступно все
	k.print();
	student z("Ivan", "Andreew", "Frolow");
	z.print();
	return 0;
}
