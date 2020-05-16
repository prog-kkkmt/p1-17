# include <stdio.h>
class CPoint
{
    private:
        int *px;                                            
        int *py;
    public:
        CPoint(int x = 0, int _y = 0);
        ~CPoint();                                        
        void Prn();         
};

CPoint::CPoint(int _x, int _y)
{
    px = new int;                                   
    *px = _x;
    py = new int;                        
    *py = _y;
}

CPoint::~CPoint()
{
    delete px;                             
    delete py;                  
}
  
void CPoint::Prn()
{
    printf("Tochka (%d, %d);\n", *px, *py);
}
   
int main()
{
    CPoint A(3,9), B;
    A.Prn();
    B.Prn();

    return 0;
}

