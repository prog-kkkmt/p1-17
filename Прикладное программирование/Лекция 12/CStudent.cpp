# include <stdio.h>
# include <string.h>
class Cstudent             //������ ����������� ������ Cstudent
{
private:
    char fio[30];                                  //��� ��������
    int bd;                                //��� �������� ��������
    int num;                              //����� �������� �������
    static int count;        //����� ���������� ��������� ��������
    static void prn_count();     //����������� �������(���� ������
public:
    CStudent(char FIO[], int);
    //�������� ������������ ������ Cstudent

    void prn();           //�������� �����(������� prn ������ Cstudent
};
CStudent::CStudent(char FIO[] = "���������", int BD =
                       1990)                  //����������� ������������ ������ Cstudent
{
    strcpy(fio, FIO);
    //����������� ��������� FIO � ����(���������� fio ������ Cstudent
    bd = BD;
    //������������ �������� ��������� BD �����(���������� bd ������
    // CStudent
    count++;                              //����������� ���������� ��������
    num = count;                         //��������� ����� �������� �������
}
int CStudent::count = 0;
//������������ ������������� ������������ �����
void CStudent::prn()               //����������� �����(������� prn ������
Cstudent
{
    printf("������� # %d, %s ������� %d;\n �����
           ���������  %d.\n", num, fio, bd, count);
           //����� ���������� � ������� �������� � � ���������� ���������
}
void CStudent::prn_count()
//����������� ����������� �����(������� prn ������ Cstudent

{
    printf("����� %d ���������.\n", count);
    //����� ���������� ���������
}
int main()
{
    CStudent student1("������ �������", 1995);
    CStudent student2("������ ��������", 1994);
    student1.prn();
    student2.prn();
    CStudent::prn_count();
    //�������� ����������� �������, ��������� ��� ������
    return 0;
}
