/*������ � ���������� ����� ���� int � float, ����� �� ���������� ��������.
���������� ���������� �������� �������� �
���� �������.*/

#include <stdio.h>
int ABS(int);                        //��������� ������� ABS
float ABS(float);
int main()
{
    int i;
    float a;
    printf("������� ����� �����: ");
    scanf(" %d",&i);
    printf("������� ������������ �����: ");
    scanf(" %f",&a);
    printf("abs(%d)=%d; abs(%f)=%f \n",i,ABS(i),a,ABS(a));
    return 0;
}
int ABS(int a)                      //����������� ������� int ABS()
{
    if (a>=0)
        return a;
    else
        return  a;
}
float ABS(float a)               //����������� ������� float ABS()
{
    if (a>=0.)
        return a;
    else
        return  a;
}
