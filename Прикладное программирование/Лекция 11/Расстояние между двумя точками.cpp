/*�������� �������, ����������� ���������� �����
����� �������. ����� ������������ ��������� ������ CPoint.*/

#include <stdio.h>
#include <math.h>
class CPoint                       //������ ����������� ������ CPoint
{
private:
    int x, y;                      //�������� �����(���������� ������
public:
    CPoint(int _x, int _y)                        //����������� ������
    {
        x = _x;
        y = _y;
    }
    int GetX()    //�������, ������������ �������� �����(���������� �
    {
        return x;
    }
    int GetY()    //�������, ������������ �������� �����(���������� y
    {
        return y;
    }
};                                  //����� ����������� ������ CPoint
float length(CPoint p1, CPoint p2)
//������� ���������� ���������� ����� ����� �������
{
    int x1, x2, y1, y2, L;
    x1 = p1.GetX();
    //��������� x1 �������� �����(���������� x ����� p1
    y1 = p1.GetY(); //��������� y1 �������� �����(���������� y ����� p1
    x2 = p2.GetX();
    //��������� x2 �������� �����(���������� x ����� p2
    y2 = p2.GetY();
    //��������� y2 �������� �����(���������� y ����� p2
    L = sqrt(pow(x2-x1, 2.0) + pow(y2-y1, 2.0));
    //���������� ���������� ����� ������� �� ������� ��������
    return L; //������� ������������ �������� L � ���������� �������
}
int main()
{
    CPoint p1(3, 0), p2(0, 4);
    printf("Length = %3.2f\n", length(p1, p2));
    return 0;
}
