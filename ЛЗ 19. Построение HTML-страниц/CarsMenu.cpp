#include <iostream>
#include <vector>
#include <fstream>
#include <clocale>

#include "Cars.hpp"
#include "AboutProg.hpp"

const int CARCODE = 0;
const int MODEL = 1;

const int DEC = 0;
const int ASC = 1;

const int EXITCODECARS = 6;

int chooseFieldInCars(){
                //if (setlocale(LC_ALL, "Russian") == NULL){
                    //puts("Unable to set locale");
                //}

                cout << "0: ��� ������" << endl;
                cout << "1: �����" << endl;

                cout << "�������� ���� ��� ���������: ";

                int code;
                cin >> code;

                cout << endl;

                return code;
}

int menu(Cars &carsTable, ofstream &f)
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
                carsTable.addRow(bC, nm);
                f << "���������� ������. Done!" << endl;
                break;
            }
            case 1:{
                int n;
                cout << "������� ����� ������: ";
                cin >> n;

                carsTable.deleteRow(n);

                f << "�������� ������. Done!" << endl;
                break;
            }
            case 2:{
                int n;
                cout << "������� ����� ������: ";
                cin >> n;

                int code = chooseFieldInCars();

                cout << "������� ����� ��������: ";
                switch (code){
                    case MODEL:{
                        string newStrValue;
                        cin >> newStrValue;
                        carsTable.changeStrRow(n, code, newStrValue);
                        break;
                    }
                    case CARCODE:{
                        int newIntValue;
                        cin >> newIntValue;
                        carsTable.changeIntRow(n, code, newIntValue);
                        break;
                    }
                    default:
                        cout << "Error";
                }

                f << "�������������� ������. Done!" << endl;
                break;
            }
            case 3:{
                f << carsTable;
                f << endl;
                f << "����� � ����. Done!" << endl;
                break;
            }
            case 4:{
                cout << "�������� ���� ��� ����������" << endl;
                int code = chooseFieldInCars();

                int order;
                cout << "�������� ��� ����������" << endl;
                cout << "0: �� ��������" << endl;
                cout << "1: �� �����������" << endl;
                cin >> order;
                carsTable.sortRows(code, order);
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

    }while (num != EXITCODECARS);

    return 0;
}
