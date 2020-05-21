#include <iostream>

using namespace std;

class Cpoint
{
	private:
		int x;
		int y;
	public:
		Cpoint(int _x, int _y); 
		int GetX();
		int GetY();

};

Cpoint :: Cpoint(int _x, int _y) : x(_x), y(_y)
		{}
int Cpoint :: GetX()
	{
		return x;
	}
int Cpoint :: GetY()
	{
		return y;
	}

int main()
{
	Cpoint A(3, 4);
	cout << "Segment : (" << A.GetX() << "," << A.GetY() << ")" << endl;
	return 0;
}
