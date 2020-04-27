#ifndef AD_H_INCLUDED
#define AD_H_INCLUDED
#include <iostream>
#include <clocale>
class student{
public:
    friend class group;
    friend std::ostream& operator<< (std::ostream &out, const student &person);
    friend std::ostream& operator << (std::ofstream &out, const student &p);
    student()
    {
        setlocale(0,"");
        std::cout<<"¬ведите им€ - ";
        std::cin>>this->name;
        std::cout<<"¬ведите фамилию - ";
        std::cin>>this->second_name;
        std::cout<<"¬ведите отчество - ";
        std::cin>>this->father_name;
        _absenteeisms = new bool[0];
        EstimationDay = new int[0];
        Estimation = 0.0;
    };
    student(std::string _name, std::string _second_name, std::string _father_name){
        name=_name;
        second_name=_second_name;
        father_name=_father_name;
        _absenteeisms = new bool[0];
        EstimationDay = new int[0];
        Estimation = -1.0;
    }
    virtual ~student(){
        delete [] _absenteeisms;
        delete [] _absenteeisms;
    }
    void PrintAllInformation(size_t k);///сделанно пополам
    void AppendDay(size_t days);///выполнено
public:
    std::string name;
    std::string second_name;
    std::string father_name;
    bool * _absenteeisms;
    int * EstimationDay;
    int KolAbsenteeisms = 0;
    double Estimation = 0.0;
};

class group{
public:
    friend class student;
    void PrintAllInformation();
    friend std::ostream& operator<< (std::ostream &out, const group &person);///сделанно
    friend std::ofstream& operator << (std::fstream &os, const group &p);
    void SwapAll(student &ob1, student &obj2);
    group(){
        setlocale(0,"");
        day = 0;
        std::cout<<"введите количество студентов - ";
        std::cin>>_size;
        persons = new student[_size];
        for(size_t i=0; i<_size; i++)
            persons[i];
    };
    group(size_t siz){
        this->_size = siz;
        std::cin>>_size;
        persons = new student[_size];
        for(int i=0; i<_size; i++)
            persons[i];
    };
    void NewDay();///сделанно
    void sorted(size_t flag = 0);///сделанно
    void game();///сделанно


protected:
    size_t _size;
    size_t day;
    student *persons;
};


#endif // AD_H_INCLUDED
