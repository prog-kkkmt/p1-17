///���������: ������� �������

#include <stdio.h>
#include <string.h>
#include <locale>

class CStudent
{
private:
    char fio[30];
    int bd;
    int num;
    static int count;
public:
    CStudent( char FIO[], int);
void prn();
};
CStudent::CStudent(char FIO[] = "���������", int BD = 1990)
{
    strcpy(fio, FIO);
    bd = BD;
count ++;
num = count;
}
int CStudent::count = 0;

void CStudent::prn()
{
    printf("������� # %d, %s ������� %d;\n ����� ��������� %d.\n", num, fio, bd, count);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    CStudent student1("������ �������", 1995);
    CStudent student2("������ ��������", 1994);
    student1.prn();
    student2.prn();
    return 0;
}


