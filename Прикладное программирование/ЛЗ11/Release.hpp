#ifndef RELEASE_HPP_
#define RELEASE_HPP_
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Release{

    int planCode; //��� ����
    int prodCode; // ��� �������
    int quan;//����������

};

void InPutRelease(vector <Release> &rel); //������� �����
void OutPutRelease(ofstream &f, vector <Release> &rel); //������� ������ � ����
void OutPutHtmlRelease(ofstream &f, vector <Release> &rel);
void EditRelease(vector <Release> &rel); //������� ��������������
void RemoveRelease(vector <Release> &rel); //������� ��������
void SortRelease(vector <Release> &rel); //������� ���������� �� ���� �����
void AboutProgRelease(ofstream &f); //���������� � ���� ���������� � ���������
void funcRelease();

#endif //RELEASE_HPP_



