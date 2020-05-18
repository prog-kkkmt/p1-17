/*Калькуляция: Код калькуляции, Код изделия, Код статьи, сумма*/
#include "Costing.hpp"

void InPut(vector <Costing>& cost){
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

void OutPut(ofstream &f, vector <Costing>& cost){
	for (unsigned i = 0; i < cost.size() ; i++)
	{

		f << cost.at(i).CostCode << "\t" ;
        f << cost.at(i).ProductName<< "\t";
        f << cost.at(i).ItemCode<< "\t";
        f << cost.at(i).sum << endl;
	}
	f << "________________________"<< endl;
}



void Remove(vector <Costing> &cost)
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

void Edit (vector <Costing> &cost)
{
    int code;
    int num, buf;

    cout << "Введите код калькуляции измениемой записи: ";
    cin >> code;
    cout << "0: Код изделия" << endl;
    cout << "1: Код статьи" << endl;
    cout << "2: Сумма" << endl;

    for (unsigned i = 0; i < cost.size(); i++) {
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
            for (unsigned i = 0; i < cost.size() - 1; i++)
            for (unsigned j = i; j < cost.size(); j++)
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
            for (unsigned i = 0; i < cost.size() - 1; i++)
                for (unsigned j = i; j < cost.size(); j++)
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
void funcCosting()
{
    ofstream f("Costing.txt");
    vector <Costing> cost;
    int num;


    cout << "0: Добавление записи"<< endl;
    cout << "1: Удаление записи"<< endl;
    cout << "2: Редактирование записи"<< endl;
    cout << "3: Печать"<< endl;
    cout << "4: Сортировка" << endl;
    cout << "5: О программе" << endl;
    cout << "6: Выход"<< endl;

    do{
        cout << "Выберите номер действия: ";
        cin >> num;
        switch(num){
        case 0:
            InPut(cost);
            f << "Добавление записи. Done!" << endl;
            break;
        case 1:
            Remove(cost);
            f << "Удаление записи. Done!" << endl;
            break;

        case 2:
            Edit(cost);
            f << "Редактирование записи. Done!" << endl;
            break;

        case 3:
            OutPut(f, cost);
            f << "Вывод в файл. Done!" << endl;
            break;

        case 4:
            Sort(cost);
            f << "Сортировка. Done!" << endl;
            break;
        case 5:
            AboutProg(f);
            break;
        case 6:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Error" << endl;
        }

    }while (num != 6);
}
