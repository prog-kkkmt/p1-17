#ifndef COSITEMS_HPP_
#define COSTITEMS_HPP_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct CostItem
 {
    int itemCode; //��� c����
    string name; // ��������

 };

void InPutItem(vector <CostItem> &item); //������� �����
void OutPutItem(ofstream &f, vector <CostItem> &item); //������� ������ � ����
void EditItem(vector <CostItem> &item); //������� ��������������
void RemoveItem(vector <CostItem> &item); //������� ��������
void SortItem(vector <CostItem> &item); //������� ���������� �� ������ �������
void AboutProgItem(ofstream &f); //���������� � ���� ���������� � ���������
void funcCostItem();

#endif //COSTITEMS_HPP_



