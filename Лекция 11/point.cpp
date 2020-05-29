#include <iostream>
using namespace std;

class Cpoint
{
	private:
		int *x; //���� x
		int *y; //���� y
	public:
		Cpoint(int x = 0, int y = 0); //�������� ������������
		void out();
		~Cpoint(); //�������� �����������
};

Cpoint :: Cpoint(int _x, int _y) //����� ������ ��� �������� ��������� �����
{

	x = new int;
	*x = _x;
	y = new int;
	*y = _y;
}

void Cpoint :: out()
{
	cout << "Segment : (" << *x << "," << *y << ")" << endl;
}

Cpoint :: ~Cpoint() //�������� ������
{
	delete x;
	delete y;
}

int main()
{
	int x, y;
    cout<<"������� ���������� x";
	cin>>x;
	cout<<"������� ���������� y";
	cin>>y;
	Cpoint A(x, y), B;
	A.out();
	B.out();
	return 0;
}
