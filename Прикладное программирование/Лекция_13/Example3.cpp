#include <iostream>

using namespace std;

class pointer
{
private:
        int *pa;
public:
	pointer()
	{	
   		cout <<"Выделяем память для членов базового класса" << endl;
   		pa = new int;
   		*pa = 456;
	}
	~pointer()
	{
   		cout <<"Освобождаем память в базовом классе" << endl;
   		delete pa;
	}
	void info()
	{	
   		cout << "*pa = " << *pa;
    
	}
};

class pointer_s : public pointer                    
{
private:
	float *px;
public:
   	pointer_s() : pointer(){
   		cout << "Выделяем память в производном классе" << endl;
   		px = new float;
   		*px = 5.67;
	}
	~pointer_s()
	{	
    		cout << "Освобождаем память в производном классе" << endl;
   		delete px;
	}
	void info()
	{
   		pointer::info();                     
   		cout << "*px = " << *px << endl;
  
	}
};

int main()
{
	pointer_s pp;
        pp.info();

        return 0;
}
