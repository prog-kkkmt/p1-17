#include <iostream>

using namespace std;


struct IntArray
{
   explicit IntArray (size_t size) : size(size), data(new int[size])
   {}
   ~IntArray()
   {
        delete [] data;
   }
   size_t size;
   int * data;
};

int main()
{

}
