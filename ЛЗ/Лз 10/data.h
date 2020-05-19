#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <cctype>
using namespace std;
struct Category {
	int categoryiD;
	string category_name;
};

struct Room {
	int roomiD;
	int categoryiD;
	int num;
	int beds;
};

struct Person {
	int personiD;
	string Fio;
	string passport;
};

struct LockedRoom {
	int lockedRoomiD;
	int personiD;
	int roomiD;
	string star;
	string finis;
};

void Initialization();
void Save();
void printDefaultMenu();
void Menu();
void About(bool *exit);//� ���������
void StructMenu(bool *exit);//�������� �������
void SortMenu(bool *exit);//�������� ����������
void sortRoom();
void sortLockedRoom();
void sortCategory();
void sortPerson();
void printRoom();//������ ������� 
void printLockedRoom();//������� ������   
void printCategory();//��������� ������� 
void printPerson();//���������� � �����������
void EditMenu(bool *exit);// �������������� �������
void editRoom();//+
void editLockedRoom();
void editCategory();
void editPerson();
int getInt(); //�������� �� ���������� ���� �����
/*5. ���������.
� ���� ������ �������� �������� � ��������� � ������� ����� ������������ ������� ������ ��������� � �����������.
�������: ��������� (��� ���������, ��������); ������ (���
������, ��� ���������, �����, ����); �������� (��� ����������,
���, �������); ���������� (��� ����������, ��� ����������, ���
������, ���� ������, ���� ����������).
����������:
� ���������� ��������� ��������� �������, �� ���� ���, � ������� �� �������� ��������;
� ������������� ������� ��������� (� ���������) ������� ��
����������.
*/