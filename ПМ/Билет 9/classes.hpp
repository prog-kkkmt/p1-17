#ifndef CLASSES_HPP
#define CLASSES_HPP

#include "structors.hpp"

#include <iostream>
#include <string>

using namespace std;

class Prof
{
public:
    Prof();
    int prof_str = 0;
    prostr *ptr_1;
};

class Pos
{
public:
    Pos();
    int pos_str = 0;
    posstr *ptr_2;
};

class Vac
{
public:
    Vac();
    int vac_str = 0;
    void print_act_vac();
    void print_sred_oklad();
    vacstr *ptr_3;

    PSL levels;
    Edu education;
    Pos names;
    Prof prof;
    
};

class PSL
{
public:
    PSL();
    pslstr *ptr_4;
    int psl_str = 0;
};

class Edu
{
public:
    Edu();
    int edu_str = 0;
    edustr *ptr_5;
};

#endif