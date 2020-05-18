/** Статьи затрат: Код статьи, название */

#include "CostItems.hpp"

void InPutItem(vector <CostItem>& item){
    CostItem buf;
    int n;
    cout << "Введите кол-во записей: ";
    cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> buf.itemCode >> buf.name;
        	item.push_back(buf);
	}
}

void OutPutItem(ofstream &f, vector <CostItem>& item){
	for (unsigned i = 0; i < item.size() ; i++)
	{
        f << item.at(i).itemCode << "\t";
        f << item.at(i).name << endl;
	}
	f << "________________________"<< endl;
}



void RemoveItem(vector <CostItem> &item)
{
        int m;
        int code;

        cout  << "Введите кол-во удаляемых записей: ";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cout << "Введите код статьи удаляемой записи: ";
            cin  >> code;
            item.erase(remove_if(item.begin(), item.end(), [code](const CostItem &item){ return item.itemCode == code; }), item.end());
        }


}

void EditItem (vector <CostItem> &item)
{
    int code;
    int num;

    cout << "Введите код статьи измениемой записи: ";
    cin >> code;
    cout << "1: Код статьи" << endl;
    cout << "2: Название" << endl;

    for (unsigned i = 0; i < item.size(); i++) {
        if (item.at(i).itemCode == code) {
            cin >> num;
            switch (num) {
                case 1:
                    {
                        int buf;
                        cin >> buf;
                        item.at(i).itemCode = buf;
                        break;
                    }

                case 2:
                    {
                        string buf;
                        cin >> buf;
                        item.at(i).name = buf;
                        break;
                    }

                default: break;
            }
        }
    }
}

void SortItem(vector <CostItem> &item) // Функция сортировки по коду статьи
{
    CostItem buff;
    int num;

    cout << "Выберите тип сортировки" << endl;
    cout << "0: По возрастанию" << endl;
    cout << "1: По убыванию" << endl;
    cin >> num;
    switch(num){
        case 0:
            for (unsigned i = 0; i < item.size() - 1; i++)
            for (unsigned j = i; j < item.size(); j++)
            {
                if (item.at(i).itemCode > item.at(j).itemCode)
                {

                    buff = item.at(i);
                    item.at(i) = item.at(j);
                    item.at(j) = buff;
                }
            }
            break;
        case 1:
            for (unsigned i = 0; i < item.size() - 1; i++)
                for (unsigned j = i; j < item.size(); j++)
                {
                    if (item.at(i).itemCode < item.at(j).itemCode)
                    {

                        buff = item.at(i);
                        item.at(i) = item.at(j);
                        item.at(j) = buff;
                    }
                }
            break;
        default:
            cout << "Error!";
            break;
    }

}

void AboutProgItem(ofstream &f)
{
    f << "Статьи затрат (Код статьи, Название)" << endl;
    f << "Источник: Экономическая информатика: лабораторный практикум / сост. О.В. Гусятинер, Л.Б. Гусятинер. – Ковров: ГОУ ВПО «КГТА имени В.А. Дегтярева», 2009" << endl;
    f << "https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf" << endl;
    f << "Выполнила: Попкова Алена П1-17" << endl;
    f << "18.05.2020"<< endl;
    f << "Функции программы:  Добавление записи, Удаление записи, Редактирование записи, Печать в файл, Сортировка, Вывод информаци \*О программе\* в файл" << endl;
}

void funcCostItem()
{
    ofstream f("CostItem.txt");
    vector <CostItem> item;
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
            InPutItem(item);
            f << "Добавление записи. Done!" << endl;
            break;
        case 1:
            RemoveItem(item);
            f << "Удаление записи. Done!" << endl;
            break;

        case 2:
            EditItem(item);
            f << "Редактирование записи. Done!" << endl;
            break;

        case 3:
            OutPutItem(f, item);
            f << "Вывод в файл. Done!" << endl;
            break;

        case 4:
            SortItem(item);
            f << "Сортировка. Done!" << endl;
            break;
        case 5:
            AboutProgItem(f);
            break;
        case 6:
            break;

        default:
            cout << "Error" << endl;
        }

    }while (num != 6);
}


