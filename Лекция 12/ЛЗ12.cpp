#include <iostream>

///���� �������� ��������� ������������ ������� ���������� �������
using namespace std;
class student{
	public:
student(){///����������� �� ����������
	setlocale(0,"");
	cout<<"������� ��� ";
	cin>>name;
	cout<<"������� �������� ";
	cin>>lastname;
	cout<<"������� ������� ";
	cin>>secondname;
}
student(string _temp, string _tempn, string _Temp){///����������� � ����������
	name=_temp;
	lastname = _tempn;
	secondname = _Temp;
}

///���������� �� ���������

void print(){
    cout<<name<<"\t"<<lastname<<"\t"<<secondname<<endl;
}
private:
	string name;///�������� ���������� ��� ����
protected:
	string lastname;///�������� ������ ��� ������������
public:
	string secondname;///��������� �������� ����������
};

int main()
{
	student k;
	///k.name = "Ira"; - ����� �� ���������
	///k.lastname = "Ira"; - ��������� ������ � ������� ������������
	///k.secondname = "Ira"; - ���������

	///����� ������� ��� ��� Frend ��������� ������� �� ������ ������� ����. �� �������� ���
	k.print();
	student z("Ivan", "Andreew", "Frolow");
	z.print();
	return 0;
}
