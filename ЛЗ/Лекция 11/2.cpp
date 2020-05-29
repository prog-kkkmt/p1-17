# include <stdio.h>
class CPoint
{
    private:
        int x;
        int y;
    public:
        CPoint();                 
        CPoint(int, int);
    void Prn();      
};
    CPoint::CPoint()          
    {
        x = y = 0;
    }

    CPoint::CPoint(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    
    void CPoint::Prn()        
    {
        printf("Tochka (%d, %d);\n", x, y);
    }
      
    int main()
    {
        CPoint A(3,9);
        A.Prn();
       
       return 0;
    }
