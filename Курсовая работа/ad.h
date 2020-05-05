#ifndef AD_H_INCLUDED
#define AD_H_INCLUDED
#include <iostream>
#include <fstream>
#include <clocale>
class student{///����� ������������ ��� ���������� � ������� ��������������� ��� ������ � ����� ���������
public:
    friend class group;
    friend std::ostream& operator<< (std::ostream &out, const student &person);///���������� ��������� ������ ��� ������ ������ ���������� � ��������
    student()///����������� �� ���������
    {
        setlocale(0,"");
        std::fstream file("groupe.txt");
        if(file.is_open()){
             _absenteeisms = new bool[0];
            EstimationDay = new int[0];
            Estimation = 0.0;
        }
        else{
            std::cout<<"������� ��� - ";
            std::cin>>this->name;
            std::cout<<"������� ������� - ";
            std::cin>>this->second_name;
            std::cout<<"������� �������� - ";
            std::cin>>this->father_name;
            _absenteeisms = new bool[0];
            EstimationDay = new int[0];
            Estimation = 0.0;
        }
    };
    student(std::string _name, std::string _second_name, std::string _father_name){///����������� � �����������
        name=_name;
        second_name=_second_name;
        father_name=_father_name;
        _absenteeisms = new bool[0];
        EstimationDay = new int[0];
        Estimation = 0.0;
    }
    virtual ~student(){///����������
        delete [] _absenteeisms;
        delete [] _absenteeisms;
    }
    void PrintAllInformation(size_t k);///����� ������ ���������� � ������ � � ������ �������� �� �����������
    void AppendDay(size_t days);///������� ������� ������� ����� ���� � ������ � �������� ���������� ��� ������� ��������
public:
    std::string name;///���������� ��� �������� �����
    std::string second_name;///���������� ��� �������� �������
    std::string father_name;///���������� ��� �������� ��������
    bool * _absenteeisms;///������������ ������ ��������(��� ������ ������������� ���������� ����
    int * EstimationDay;///������������ ������ ������(��� ������ ������������� ���������� ����
    int KolAbsenteeisms = 0;///���������� ��������
    double Estimation = 0.0;///������� ������
};

class group{///����� ������������ ��� ���������� � ������� ��� ������ � ������������ �������� �������� ������ student
public:
    friend class student;///������ ����� student ������������� ��� �� �� ���� ��� ������ �� ���� ���������� ������� ������
    void PrintAllInformation();///����� ���� ����������� ������
    friend std::ostream& operator<< (std::ostream &out, const group &person);///���������� ��������� ������
    friend std::fstream& operator << (std::ofstream &os, const group &person);///���������� ��������� ������ � ����
    void SwapAll(student &ob1, student &obj2);///������� ��� ������ ���� ������� student
    group(){
        std::fstream file("groupe.txt");
        if(!file.is_open()){
            setlocale(0,"");
            day = 0;
            std::cout<<"������� ���������� ��������� - ";
            std::cin>>_size;
            persons = new student[_size];
            for(size_t i=0; i<_size; i++)
            persons[i];
        }
        else{
            std::string temp;
            file>>temp>>day>>temp>>_size;
            persons = new student[_size];
            for(int i=0; i<_size; i++){
                file>>temp;
                file>>persons[i].name>>persons[i].second_name>>persons[i].father_name;
                persons[i].KolAbsenteeisms=0;
                persons[i].Estimation=0;
                persons[i]._absenteeisms = new bool[day];
                persons[i].EstimationDay = new int[day];
                file>>temp;
                for(int j =0; j<day; j++){
                    file>>persons[i]._absenteeisms[j];
                    if(persons[i]._absenteeisms[j]==1)
                        persons[i].KolAbsenteeisms++;
                }
                file>>temp;
                for(int j =0; j<day; j++){
                    file>>persons[i].EstimationDay[j];
                    persons[i].Estimation += persons[i].EstimationDay[j];
                }
                if(day!=0)
                    persons[i].Estimation /= day;
            }
        }
    }
    void NewDay();///������� �� ���������� ���
    void sorted(size_t flag = 0);///������� ���������� � ���������� �� ��������� = 0

protected:
    size_t _size;///���������� ��� �������� ���������� ��������
    size_t day;///���������� ��� ���������� ��������
    student *persons;///������������ ������ ��������
};


#endif // AD_H_INCLUDED
