#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class buses
{
public:
	int bus_ID; //id
	string bus_brand; //�����
	string bus_number; // ��������
	int bus_capacity; // �����������
	void input();
	void total_capacity();
};

class stations
{
public:
	int station_ID; // id �������
	string station_name; // ������������ 
	void input();
};

class cruises
{
public:
	int cruise_ID; // id �����
	int station_ID; // id �������
	int bus_ID; //id ��������
	string departure_time; // ����� �����������
	void input();
};
