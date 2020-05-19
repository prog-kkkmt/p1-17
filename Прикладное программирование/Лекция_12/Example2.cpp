# include <iostream>
# include <string.h>

class Cstudent                   
{
    private:
        char fio[30];                                        //ФИО студента
        int bd;                                      //год рождения студента
        int num;                                    //номер текущего объекта
        static int count;              //общее количество созданных объектов
    public:
        CStudent(char FIO[], int );
        void prn();          
};      
 
   
CStudent::CStudent(char FIO[] = "Николенко", int BD = 1990)
{
    strcpy(fio, FIO);
    bd = BD;
    count++;                        
    num = count;                        
}

int CStudent::count = 0;                
void CStudent::prn()
{
    cout <<"Студент" <<  num << ", " << fio << "родился " << bd << ";" << endl;
    cout << "Всего студентов" << count;
}
  
  
int main()
{
    CStudent student1("Иванов Николай", 1995);
    CStudent student2("Лершов Владимир", 1994);
    student1.prn();
    student2.prn();
    
    return 0;
}
