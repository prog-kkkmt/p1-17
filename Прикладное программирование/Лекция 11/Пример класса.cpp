/*�������� ������ ������ CPoint � �������������.*/
# include <stdio.h>

class CPoint                     //������ �������� ������ CPoint
{
private:                      //����������� �������� ����� ������
    int x;                                                  //���� �
    int y;                                                  //���� y
public:                      //����������� �������� ����� ������
    CPoint(int, int); //�������� ������������ � ����� �����������
    void Prn();                      //�������� ������ ������ Prn
};                                //����� �������� ������ CPoint
CPoint::CPoint(int _x, int _y)
//���������� ������������ ������ CPoint
{
    x = _x;
    y = _y;
}
void CPoint::Prn()        //���������� ������ Prn ������ CPoint
{
    printf("Tochka (%d, %d);\n", x, y);
}
int main()
{
    CPoint A(3,9);
    A.Prn();
    return 0;
}
