#include <iostream>
#include <vector>
#include <fstream>
#include "Sales.hpp"

using namespace std;

int menu(Sales &salesTable);
void AboutProg(ofstream &f);

int main(){
    Sales salesTable = Sales();
    salesTable.addRow(1, 21, "n51m24", 41, "01.01.2001", 101);
    salesTable.addRow(3, 23, "forDelete", 43, "03.03.2003", 103);
    salesTable.addRow(4, 24, "u72y2q", 44, "04.04.2004", 104);
    salesTable.addRow(2, 22, "ha451a", 42, "02.02.2002", 102);

    menu(salesTable);

    /*
    cout << salesTable;
    cout << endl;
    salesTable.deleteRow(2);
    cout << salesTable;
    cout << endl;
    salesTable.sortRows(MANAGERCODE, ASC);
    cout << salesTable;
    cout << endl;
    salesTable.changeIntRow(3, MANAGERCODE, 3);
    cout << salesTable;
    */

    return 0;
}

int menu(Sales &salesTable)
{
    int num;
    ofstream f("test.txt");

    setlocale(LC_ALL, "Russian");

    cout << "0: ���������� ������"<< endl;
    cout << "1: �������� ������"<< endl;
    cout << "2: �������������� ������"<< endl;
    cout << "3: ������"<< endl;
    cout << "4: ����������" << endl;
    cout << "5: � ���������" << endl;
    cout << "6: �����"<< endl;

    do{
        cout << "�������� ����� ��������: ";
        cin >> num;
        switch(num){
            case 0:{
                int mC, cC, bC, p;
                string lP, d;
                cin >> mC >> cC >> lP >> bC >> d >> p;
                salesTable.addRow(mC, cC, lP, bC, d, p);
                f << "���������� ������. Done!" << endl;
                break;
            }
            case 1:{
                int n;
                cout << "������� ����� ������: ";
                cin >> n;

                salesTable.deleteRow(n);

                f << "�������� ������. Done!" << endl;
                break;
            }
            case 2:{
                int n;
                cout << "������� ����� ������: ";
                cin >> n;
                cout << "�������� ���� ��� ���������: ";

                int code;
                cin >> code;
                cout << "0: ��� ���������" << endl;
                cout << "1: ��� ������" << endl;
                cout << "2: ��������������� �����" << endl;
                cout << "3: ��� ����������" << endl;
                cout << "4: ����" << endl;
                cout << "5: ����" << endl;

                cout << "������� ����� ��������: ";

                switch (code){
                    case LICENSEPLATE:
                        ;
                    case DATE:{
                        string newStrValue;
                        cin >> newStrValue;
                        salesTable.changeStrRow(n, code, newStrValue);
                        break;
                    }
                    case MANAGERCODE:
                        ;
                    case CARCODE:
                        ;
                    case BUYERCODE:
                        ;
                    case PRICE:{
                        int newIntValue;
                        cin >> newIntValue;
                        salesTable.changeIntRow(n, code, newIntValue);
                        break;
                    }
                    default:
                        cout << "Error";
                }

                f << "�������������� ������. Done!" << endl;
                break;
            }
            case 3:{
                f << salesTable;
                f << endl;
                f << "����� � ����. Done!" << endl;
                break;
            }
            case 4:{
                int pole;
                cout << "�������� ���� ��� ����������" << endl;
                cin >> pole;

                int order;
                cout << "�������� ��� ����������" << endl;
                cout << "0: �� ��������" << endl;
                cout << "1: �� �����������" << endl;
                cin >> order;
                salesTable.sortRows(pole, order);
                f << "����������. Done!" << endl;
                break;
            }
            case 5:{
                AboutProg(f);
                break;
            }
            case 6:{
                cout << "�����" << endl;
                break;
            }
            default:
                cout << "Error" << endl;
        }

    }while (num != 6);
}

void AboutProg(ofstream &f)
{
    f << "������� (��� ���������, ��� ����������, ��������������� �����, ��� ����������, ����, ����)" << endl;
    f << "��������: ������������� �����������: ������������ ��������� / ����. �.�. ���������, �.�. ���������. � ������: ��� ��� ����� ����� �.�. ���������, 2009" << endl;
    f << "https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf" << endl;
    f << "��������: ��������� ������ �1-17" << endl;
    f << "15.05.2020"<< endl;
    f << "������� ���������:  ���������� ������, �������� ������, �������������� ������, ������ � ����, ����������, ����� ��������� \"� ���������\" � ����" << endl;
}
