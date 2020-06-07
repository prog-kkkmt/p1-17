#include <iostream>
#include <vector>
#include <fstream>

#include "Sales.hpp"
#include "AboutProg.hpp"

const int MANAGERCODE = 0;
const int CARCODE = 1;
const int LICENSEPLATE = 2;
const int BUYERCODE = 3;
const int DATE = 4;
const int PRICE = 5;

const int DEC = 0;
const int ASC = 1;

const int EXITCODESALES = 6;

int chooseFieldInSales(){
                //if (setlocale(LC_ALL, "Russian") == NULL){
                    //puts("Unable to set locale");
                //}

                cout << "0: ��� ���������" << endl;
                cout << "1: ��� ������" << endl;
                cout << "2: ��������������� �����" << endl;
                cout << "3: ��� ����������" << endl;
                cout << "4: ����" << endl;
                cout << "5: ����" << endl;

                cout << "�������� ���� ��� ���������: ";

                int code;
                cin >> code;

                cout << endl;

                return code;
}

int menu(Sales &salesTable, ofstream &f)
{
    int num;

    //if (setlocale(LC_ALL, "Russian") == NULL){
        //puts("Unable to set locale");
    //}

    do{
        cout << "0: ���������� ������"<< endl;
        cout << "1: �������� ������"<< endl;
        cout << "2: �������������� ������"<< endl;
        cout << "3: ������"<< endl;
        cout << "4: ����������" << endl;
        cout << "5: � ���������" << endl;
        cout << "6: �����"<< endl;

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

                int code = chooseFieldInSales();

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
                cout << "�������� ���� ��� ����������" << endl;

                int code = chooseFieldInSales();

                int order;
                cout << "�������� ��� ����������" << endl;
                cout << "0: �� ��������" << endl;
                cout << "1: �� �����������" << endl;
                cin >> order;
                salesTable.sortRows(code, order);
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

    }while (num != EXITCODESALES);

    return 0;
}
