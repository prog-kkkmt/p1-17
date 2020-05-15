#ifndef COSTING_HPP_
#define COSTING_HPP_
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Costing
 {
    int CostCode; //��� �����������
    int ProductName; // ��� �������
    int ItemCode; //��� ������
    int sum; //�����
 };

void InPut(vector <Costing> &cost); //������� �����
void OutPut(ofstream &f, vector <Costing> &cost); //������� ������ � ����
void Edit(vector <Costing> &cost); //������� ��������������
void Remove(vector <Costing> &cost); //������� ��������
void Sort(vector <Costing> &cost); //������� ���������� �� ������ �������
void AboutProg(ofstream &f); //���������� � ���� ���������� � ���������
#endif //COSTING_HPP_

