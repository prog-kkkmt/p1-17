#ifndef PRODUCTS_HPP_
#define PRODUCTS_HPP_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Product
 {
    int prodCode; //��� �������
    string name; // ��������

 };

void InPutProd(vector <Product> &prod); //������� �����
void OutPutProd(ofstream &f, vector <Product> &prod); //������� ������ � ����
void EditProd(vector <Product> &prod); //������� ��������������
void RemoveProd(vector <Product> &prod); //������� ��������
void SortProd(vector <Product> &prod); //������� ���������� �� ���� �������
void AboutProgProd(ofstream &f); //���������� � ���� ���������� � ���������
void funcProduct();

#endif //PRODUCTS_HPP_




