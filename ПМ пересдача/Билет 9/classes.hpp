#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Prof
{
public:
    Prof();
    int prof_str = 0;
    struct prostr{
    string pro_code;
	string pro;};
	prostr *ptr_1; 
};

class Pos
{
public:
    Pos();
    int pos_str = 0;
    struct posstr{
    string pos_code;
	string name;
};
	posstr *ptr_2;
};

class Vac
{
public:
    Vac();
    int vac_str = 0;
    void print_act_vac();
    void print_sred_oklad();
    struct vacstr{
	string vac_code;
	string date;
	string vac_pos;
	string actuality;
	string vac_pro_code;
	string vac_edu_code;
	string vac_psl_code; 
	int salary = 0;};
	vacstr *ptr_3;
   
    
};

class PSL
{
public:
    PSL();
    struct pslstr{
    string psl_code;
	string level;
	};
	pslstr *ptr_4;
    int psl_str = 0;
};

class Edu
{
public:
    Edu();
    int edu_str = 0;
    struct edustr{
    string edu_code;
	string edu;
};
	edustr *ptr_5;
};

class Menu
{
public:
        void menu();
        int select_num(int n);
        void clear();
};
