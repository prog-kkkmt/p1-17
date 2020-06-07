#include <iostream>
#include <vector>
#include <fstream>
#include <clocale>

#include "Buyers.hpp"
#include "AboutProg.hpp"

const int BUYERCODE = 0;
const int NAME = 1;

const int DEC = 0;
const int ASC = 1;

const int EXITCODEBUYERS = 6;

int chooseFieldInBuyers(){
                //if (setlocale(LC_ALL, "Russian") == NULL){
                    //puts("Unable to set locale");
                //}

                cout << "0: ��� ����������" << endl;
                cout << "1: ���" << endl;

                cout << "�������� ���� ��� ���������: ";

                int code;
                cin >> code;

                cout << endl;

                return code;
}

int menu(Buyers &buyersTable, ofstream &f)
{
    int num;

    //if (setlocale(LC_ALL, "") == NULL){
    //    puts("Unable to set locale");
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
                int bC;
                string nm;
                cin >> bC >> nm;
                buyersTable.addRow(bC, nm);
                f << "���������� ������. Done!" << endl;
                break;
            }
            case 1:{
                int n;
                cout << "������� ����� ������: ";
                cin >> n;

                buyersTable.deleteRow(n);

                f << "�������� ������. Done!" << endl;
                break;
            }
            case 2:{
                int n;
                cout << "������� ����� ������: ";
                cin >> n;

                int code = chooseFieldInBuyers();

                cout << "������� ����� ��������: ";
                switch (code){
                    case NAME:{
                        string newStrValue;
                        cin >> newStrValue;
                        buyersTable.changeStrRow(n, code, newStrValue);
                        break;
                    }
                    case BUYERCODE:{
                        int newIntValue;
                        cin >> newIntValue;
                        buyersTable.changeIntRow(n, code, newIntValue);
                        break;
                    }
                    default:
                        cout << "Error";
                }

                f << "�������������� ������. Done!" << endl;
                break;
            }
            case 3:{
                f << buyersTable;
                f << endl;
                f << "����� � ����. Done!" << endl;
                break;
            }
            case 4:{
                cout << "�������� ���� ��� ����������" << endl;
                int code = chooseFieldInBuyers();

                int order;
                cout << "�������� ��� ����������" << endl;
                cout << "0: �� ��������" << endl;
                cout << "1: �� �����������" << endl;
                cin >> order;
                buyersTable.sortRows(code, order);
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

    }while (num != EXITCODEBUYERS);

    return 0;
}
