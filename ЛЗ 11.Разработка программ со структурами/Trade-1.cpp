// ��������� �.�., ����� ����, 05.05.2020
// ������ ������������� ����������. ��������� ��������
// � �������� ������ (��� ���������� �����) ���������� ������
// ���������

#include <iostream>
using namespace std;

struct Date { // ����
    // �� ��������� ��� ���� ��������� - public
    int year; // ���
    int month; // �����
    int day; // ����
};

struct Saler { // ��������
    int salerId; // ���������� �����, ������������� (��) ��������
    string name; // ���
    string city; // �����
    double comm; // ������������ �� 0 �� 1

};

class Customer { // ��������
    // �� ��������� ��� ���� ������ private,
    // �� ���� ��� ���� ������ �� �����
public:
    int customerId; // �� ���������
    string name; // ���
    string city; // �����
    int rating; // ������� (�������� ����� �� 0 �� 200)
    int salerId; // �� �������������� ��������
};

struct Order { // �����
    int orderId; // �� ������
    int salerId; // �� ��������
    int customerId; // �� ���������
    Date date; // ���� ������
    double cost; // ����� ������
};

int main() {
    Order order;
    // ������� ��������� ������ (���������)
    //
    order.orderId = 1;
    order.salerId = 1;
    order.customerId = 1;
    order.date.year = 2019;
    order.date.month = 12;
    order.date.day = 31;
    order.cost = 125.78;

    // ���������� ��������
    cout << order.orderId << " " << order.salerId << " " <<
        order.customerId << " " << order.date.year << "." <<
        order.date.month << "." << order.date.day << " " << order.cost << endl;
    return 0;
}
