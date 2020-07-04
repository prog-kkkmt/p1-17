#ifndef STRUCTORS_HPP
#define STRUCTORS_HPP

#include <string>

using namespace std;

struct pslstr
{
    string psl_code, level;
};

struct posstr
{
    string pos_code, name;
};

struct edustr
{
    string edu_code, edu;
};

struct prostr
{
    string pro_code, pro;
};

struct vacstr
{
    string vac_code, date, vac_pos, actuality, vac_pro_code, vac_edu_code, vac_psl_code;
    int salary;
};

#endif