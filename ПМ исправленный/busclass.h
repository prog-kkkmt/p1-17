#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Buses
{
public:
	int bus_ID; //id
	string bus_brand; //�����
	string bus_number; // ��������
	int bus_capacity; // �����������
	void input();
	int total_capacity();
};

class Stations
{
public:
	int station_ID; // id �������
	string station_name; // ������������ 
	void input();
};

class Cruises
{
public:
	int cruise_ID; // id �����
	int station_ID; // id �������
	int bus_ID; //id ��������
	string departure_time; // ����� �����������
	void input();
};
