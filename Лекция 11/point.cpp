#include <iostream>
using namespace std;

class Cpoint
{
	private:
		int *x; //поле x
		int *y; //поле y
	public:
		Cpoint(int x = 0, int y = 0); //прототип конструктора
		void out();
		~Cpoint(); //прототип деструктора
};

Cpoint :: Cpoint(int _x, int _y) //выдел память для хранения координат точки
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

Cpoint :: ~Cpoint() //освобожд память
{
	delete x;
	delete y;
}

int main()
{
	int x, y;
    cout<<"Введите координату x";
	cin>>x;
	cout<<"Введите координату y";
	cin>>y;
	Cpoint A(x, y), B;
	A.out();
	B.out();
	return 0;
}
