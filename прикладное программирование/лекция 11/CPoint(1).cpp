#include <iostream>

using namespace std;

class Cpoint
{
	private:
		int x;
		int y;
	public:
		void SetX(int _x)
		{
			x = _x;
		}
		void SetY(int _y)
		{
			y = _y;
		}
		int GetX()
		{
			return x;
		}
		int GetY()
		{
			return y;
		}

};

int main()
{
	Cpoint A;
	A.SetX(3);
	A.SetY(4);
	cout << "Segment : (" << A.GetX() << "," << A.GetY() << ")" << endl;
	return 0;
}
