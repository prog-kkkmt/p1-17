#include <stdio.h>
#include <math.h>
class CPoint
{
	private:
		int x, y;
	public:
      		CPoint(int _x, int _y)           
   		{	
      			x = _x;
      			y = _y;
   		}
   		CPoint()                              
   		{	
      			x = y = 0;
   		}
   		CPoint(int a)                      
   		{                                                  
       			x = y = a;
   		}		
   	void print()              
   	{	
      		printf("Tochka: (%d, %d).\n", x, y);
   	}
};

    int main()
   {
    	CPoint p1 = 5;
    	p1.print();

     	return 0;
   }
