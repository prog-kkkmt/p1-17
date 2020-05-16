#include "Costing.hpp"
#include <algorithm>

void InPut(vector <Costing>& cost){  // Функция добавления записи
    Costing buf;
    int n;
    cout << "Введите кол-во записей: ";
    cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> buf.CostCode >> buf.ProductName >> buf.ItemCode >> buf.sum;
        	cost.push_back(buf);
	}
}

void OutPut(ofstream &f, vector <Costing>& cost){ // Функция печати в файл
	for (int i = 0; i < cost.size() ; i++)
	{

		f << cost.at(i).CostCode << "\t" ;
        f << cost.at(i).ProductName<< "\t";
        f << cost.at(i).ItemCode<< "\t";
        f << cost.at(i).sum << endl;
	}
	f << "________________________"<< endl;
}



void Remove(vector <Costing> &cost) //Функция удаления записи
{
        int m;
        int code;

        cout  << "Введите кол-во удаляемых записей: ";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cout << "Введите код калькуляции удаляемой записи: ";
            cin  >> code;
            cost.erase(remove_if(cost.begin(), cost.end(), [code](const Costing &cost){ return cost.CostCode == code; }), cost.end());
        }


}

void Edit (vector <Costing> &cost) //Функция редактирования
{
    int code;
    int num, buf;

    cout << "Введите код калькуляции измениемой записи: ";
    cin >> code;
    cout << "0: Код изделия" << endl;
    cout << "1: Код статьи" << endl;
    cout << "2: Сумма" << endl;

    for (int i = 0; i < cost.size(); i++) {
        if (cost.at(i).CostCode == code) {
            cin >> num;
            cin >> buf;
            switch (num) {
                case 0:
                    cost.at(i).ProductName = buf;
                    break;
                case 1:
                    cost.at(i).ItemCode = buf;
                    break;
                case 2:
                    cost.at(i).sum = buf;
                    break;
                default: break;
            }
        }
    }
}

void Sort(vector <Costing> &cost) // Функция сортировки по коду изделия
{
    Costing buff;
    int num;

    cout << "Выберите тип сортировки" << endl;
    cout << "0: По возрастанию" << endl;
    cout << "1: По убыванию" << endl;
    cin >> num;
    switch(num){
        case 0:
            for (int i = 0; i < cost.size() - 1; i++)
            for (int j = i; j < cost.size(); j++)
            {
                if (cost.at(i).ProductName > cost.at(j).ProductName)
                {

                    buff = cost.at(i);
                    cost.at(i) = cost.at(j);
                    cost.at(j) = buff;
                }
            }
            break;
        case 1:
            for (int i = 0; i < cost.size() - 1; i++)
            for (int j = i; j < cost.size(); j++)
            {
                if (cost.at(i).ProductName < cost.at(j).ProductName)
                {
                    buff = cost.at(i);
                    cost.at(i) = cost.at(j);
                    cost.at(j) = buff;
                }
            }
            break;
        default:
            break;

    }

}
void AboutProg(ofstream &f)
{
    f << "Калькуляция (Код калькуляции, Код изделия, Код статьи, сумма)" << endl;
    f << "Источник: Экономическая информатика: лабораторный практикум / сост. О.В. Гусятинер, Л.Б. Гусятинер. – Ковров: ГОУ ВПО «КГТА имени В.А. Дегтярева», 2009" << endl;
    f << "https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf" << endl;
    f << "Выполнила: Попкова Алена П1-17" << endl;
    f << "15.05.2020"<< endl;
    f << "Функции программы:  Добавление записи, Удаление записи, Редактирование записи, Печать в файл, Сортировка, Вывод информаци \*О программе\* в файл" << endl;
}
