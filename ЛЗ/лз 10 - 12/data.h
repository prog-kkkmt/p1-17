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
void printRoom();//������ ������� 
void printLockedRoom();//������� ������   
void printCategory();//��������� ������� 
void printPerson();//���������� � �����������
void Edit();// �������������� �������
void editRoom();//+
void editLockedRoom();
void editCategory();
void editPerson();
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
		cout << " ________________________________________ " << endl;
		cout << "|        ������ �������                  |" << endl;
		cout << "|________________________________________|" << endl;
		cout << "|  ���   |   ���     |  �����   | �����  |" << endl;
		cout << "| ������ | ��������� |          |  ����  |" << endl;
		cout << "|________________________________________|" << endl;
		*/
