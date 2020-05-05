#ifndef AD_H_INCLUDED
#define AD_H_INCLUDED
#include <iostream>
#include <fstream>
#include <clocale>
class student{///класс предназначен для переменных и функций предназначенных для работы с одним студентом
public:
    friend class group;
    friend std::ostream& operator<< (std::ostream &out, const student &person);///Перегрузка оператора вывода для вывода точной информации о студенте
    student()///конструктор по умолчанию
    {
        setlocale(0,"");
        std::fstream file("groupe.txt");
        if(file.is_open()){
             _absenteeisms = new bool[0];
            EstimationDay = new int[0];
            Estimation = 0.0;
        }
        else{
            std::cout<<"Введите имя - ";
            std::cin>>this->name;
            std::cout<<"Введите фамилию - ";
            std::cin>>this->second_name;
            std::cout<<"Введите отчество - ";
            std::cin>>this->father_name;
            _absenteeisms = new bool[0];
            EstimationDay = new int[0];
            Estimation = 0.0;
        }
    };
    student(std::string _name, std::string _second_name, std::string _father_name){///конструктор с параметрами
        name=_name;
        second_name=_second_name;
        father_name=_father_name;
        _absenteeisms = new bool[0];
        EstimationDay = new int[0];
        Estimation = 0.0;
    }
    virtual ~student(){///Диструктор
        delete [] _absenteeisms;
        delete [] _absenteeisms;
    }
    void PrintAllInformation(size_t k);///Вывод точной информации о группе и о каждом студенте по отдельности
    void AppendDay(size_t days);///функция которая добавит одень день в группу и запустит добавление дня каждому студенту
public:
    std::string name;///переменная для хранении имени
    std::string second_name;///переменная для хранении фамилии
    std::string father_name;///переменная для хранении отчества
    bool * _absenteeisms;///Динамический массив прогулов(его размер соответствует количеству дней
    int * EstimationDay;///Динамический массив оценок(его размер соответствует количеству дней
    int KolAbsenteeisms = 0;///количество прогулов
    double Estimation = 0.0;///Средняя оценка
};

class group{///класс предназначен для переменных и функций для работы с динамическим массивом объектов класса student
public:
    friend class student;///делаем класс student дружественным что бы из него был доступ ко всем параметрам данного класса
    void PrintAllInformation();///вывод всей информациио группе
    friend std::ostream& operator<< (std::ostream &out, const group &person);///перешрузка оператора вывода
    friend std::fstream& operator << (std::ofstream &os, const group &person);///перегрузка оператора вывода в файл
    void SwapAll(student &ob1, student &obj2);///функция для обмена двух классов student
    group(){
        std::fstream file("groupe.txt");
        if(!file.is_open()){
            setlocale(0,"");
            day = 0;
            std::cout<<"введите количество студентов - ";
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
    void NewDay();///функция по добавлению дня
    void sorted(size_t flag = 0);///функция сортировка с параметром по умолчанию = 0

protected:
    size_t _size;///переменная для хранении количества учащихся
    size_t day;///переменная для количества учащихся
    student *persons;///динамический массив учащихся
};


#endif // AD_H_INCLUDED
