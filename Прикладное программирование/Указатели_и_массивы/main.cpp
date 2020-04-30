/**����������� ��������� � ���� ��� ������ � �������� ����� ����� �� 10 ���������.
������ ����: ����������, ���������� �������������, ���������� �����, ������, �����.
��� ������� �������� (����� ������) ����������� �������, ����������� � �������� ����������
����� ������� �������� ������� � ���������� ���������.**/

#include <iostream>
#include "mylib.hpp"
#define SIZE 10

using namespace std;

int main()
{
    int arr[SIZE];
    int n, f;

    setlocale(LC_ALL, "Russian");

    cout << "Size of array: ";
    cin >> n;

    cout << "0: ����������"<< endl;
    cout << "1: ���������� ������������� ��������"<< endl;
    cout << "2: ���������� �����"<< endl;
    cout << "3: ������"<< endl;
    cout << "4: �����"<< endl;

    do{
        cout << "�������� ����� ��������: ";
        cin >> f;
        switch(f){
        case 0:
            input(arr, n);
            break;
        case 1:
            {
                 int *pmax =Max(arr, arr + n);
                cout <<"Max = " << *pmax << endl;
                break;
            }

        case 2:
            cout << "Sum = " << sumArray(arr, arr + n) << endl;
            break;

        case 3:
            output(arr, n);
            break;

        case 4:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Error" << endl;
        }

    }while (f != 4);


    return 0;
}
