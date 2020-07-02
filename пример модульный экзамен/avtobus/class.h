#pragma once
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
/*
������ ������� ������� �� ����� ������������� ���������� ����������
�������: 
������� (��� �������, �������� �������), 
�������� (��� ��������, ����� ��������, ��������������� �����, �����������),
����� (��� �����, ��� �������, ��� ��������, ����� �����������).
*/
//������������ ���� std
using namespace std;
//����� ���������
class buses
{
public:
	struct bus //������� (��� ��������, ����� ��������, ��������������� �����, �����������)
	{
		int bus_ID;
		string bus_brand;
		string bus_number;
		int bus_capacity;
	};
	vector<bus>list_bus;
	void load();//�������� ������ ���������
	void total_capacity();//����� ������ ���������� ����������
};

class stations
{
public:
	struct station //������� (��� �������, �������� �������)
	{
		int station_ID;
		string station_name;
	};
	vector<station>list_station;
	void load();//�������� ������ �������
};

class voyages
{
public:
	struct voyage //����� (��� �����, ��� �������, ��� ��������, ����� �����������).
	{
		int voyage_ID;
		int station_ID;
		int bus_ID;
		string departure_time;
	};
	vector<voyage>list_voyage;
	void load();//�������� ������ ������
};
 
