/*�������� ����� ������. ����� ������: ��� �����, ��� �������. �������� ����� �����������.
����� ������: ����, ������, ��������. �� ���� ���� ���� ������� �������� ����� �����, ���������� �
���� ��� ������������� �����/
*/
#include <stdio.h>
#include <string.h>
class Hero                   //������ ����������� 1(�� �������� ������ Hero
{
protected:
    char name[32];         //���������� ����(���������� name ������ Hero
    int age;                //���������� ����(���������� age ������ Hero
public:
    Hero()         //����������� ������������ ������ Hero ��� ����������
    {
        strcpy(name, "NoName");
        //����������� � ����(���������� name ������ NoName
        age = 0;                    //��������� �����(���������� age �������� 0
    }
    Hero(char* name, int age)
    //����������� ������������ ������ Hero � ����� �����������
    {
        strcpy(this -> name, name);                /*����������� �����(����������
                           name (this >name) �������� ��������� name*/
        this ->age = age;
        //��������� �����(���������� age(this >age) �������� ��������� age
    }
    void info()                              //����������� �������(����� info
    {
        printf("Hero:%s, %d\n", name, age);
        //����� �� ����� �������� ������ � �������� ������(���������� name � age
    }
};                                 //����� ����������� �������� ������ Hero
class Parametry           //������ ����������� �������� ������ Parametry
{
protected:
    int sila;       //���������� ����(���������� sila ������ Parametry
    int zashita;
    //���������� ����(���������� zashita ������ Parametry
    int skorost;
    //���������� ����(���������� skorost ������ Parametry
public:
    Parametry(int _sila = 0, int _zashita = 0,
              int _skorost = 0)
    //����������� ������ Parametry �� ���������� �� ����������
    {
        sila = _sila;
        zashita = _zashita;
        skorost = _skorost;
    }
    void info()          //����������� �����(������� info ������ Parametry
    {
        printf("Parametry: %d, %d, %d\n", sila, zashita,
               skorost);                /*����� �� ����� �������� ������ � ��������
                                   ������(���������� sila, zashita, skorost*/
    }
};                                   //����� ����������� ������ Parametry
class Warrior : public Hero, Parametry
//������ �������. ������ Warrior ���������� ������� Hero, Parametry
{
public:
    /*����������� ������������ ������ Warrior ��������������
    �������������� ������������� ������� Hero � Parametry*/
    Warrior(char* _name, int _age, int _sila, int _zashita,
            int _skorost): Hero(_name, _age), Parametry(_sila,
                        _zashita, _skorost)
    {                                                                          }
    void info()              //����������� �����(������� info ������ Warrior
    {
        printf("Warrior:\n");
        //����� �� ����� �������� ������ Warrior
        Hero::info();                  //����� �������(����� info ������ Hero
        Parametry::info();
        //����� �������(����� info ������ Parametry
    }
};                                      //����� ����������� ������ Warrior
int main()
{
    Warrior w("Ivan", 30, 100, 300, 15);
    w.info();
    return 0;
}

