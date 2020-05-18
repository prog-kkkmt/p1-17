/** Изделия: Код изделия, название */

#include "Products.hpp"

void InPutProd(vector <Product> &prod){
    Product buf;
    int n;
    cout << "Введите кол-во записей: ";
    cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> buf.prodCode >> buf.name;
        	prod.push_back(buf);
	}
}

void OutPutProd(ofstream &f, vector <Product> &prod){
	for (unsigned i = 0; i < prod.size() ; i++)
	{
        f << prod.at(i).prodCode << "\t";
        f << prod.at(i).name << endl;
	}
	f << "________________________"<< endl;
}



void RemoveProd(vector <Product> &prod)
{
        int m;
        int code;

        cout  << "Введите кол-во удаляемых записей: ";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cout << "Введите код изделия удаляемой записи: ";
            cin  >> code;
            prod.erase(remove_if(prod.begin(), prod.end(), [code](const Product &prod){ return prod.prodCode == code; }), prod.end());
        }


}

void EditProd (vector <Product> &prod)
{
    int code;
    int num;

    cout << "Введите код изделия изменяемой записи: ";
    cin >> code;
    cout << "1: Код изделия" << endl;
    cout << "2: Название" << endl;

    for (unsigned i = 0; i < prod.size(); i++) {
        if (prod.at(i).prodCode == code) {
            cin >> num;
            switch (num) {
                case 1:
                    {
                        int buf;
                        cin >> buf;
                        prod.at(i).prodCode = buf;
                        break;
                    }

                case 2:
                    {
                        string buf;
                        cin >> buf;
                        prod.at(i).name = buf;
                        break;
                    }

                default: break;
            }
        }
    }
}

void SortProd(vector <Product> &prod) // Функция сортировки по коду статьи
{
    Product buff;
    int num;

    cout << "Выберите тип сортировки" << endl;
    cout << "0: По возрастанию" << endl;
    cout << "1: По убыванию" << endl;
    cin >> num;
    switch(num){
        case 0:
            for (unsigned i = 0; i < prod.size() - 1; i++)
            for (unsigned j = i; j < prod.size(); j++)
            {
                if (prod.at(i).prodCode > prod.at(j).prodCode)
                {

                    buff = prod.at(i);
                    prod.at(i) = prod.at(j);
                    prod.at(j) = buff;
                }
            }
            break;
        case 1:
            for (unsigned i = 0; i < prod.size() - 1; i++)
                for (unsigned j = i; j < prod.size(); j++)
                {
                    if (prod.at(i).prodCode < prod.at(j).prodCode)
                    {

                        buff = prod.at(i);
                        prod.at(i) = prod.at(j);
                        prod.at(j) = buff;
                    }
                }
            break;
        default:
            cout << "Error!";
            break;
    }

}

void AboutProgProd(ofstream &f)
{
    f << "Изделия (Код изделия, Название)" << endl;
    f << "Источник: Экономическая информатика: лабораторный практикум / сост. О.В. Гусятинер, Л.Б. Гусятинер. – Ковров: ГОУ ВПО «КГТА имени В.А. Дегтярева», 2009" << endl;
    f << "https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf" << endl;
    f << "Выполнила: Попкова Алена П1-17" << endl;
    f << "18.05.2020"<< endl;
    f << "Функции программы:  Добавление записи, Удаление записи, Редактирование записи, Печать в файл, Сортировка, Вывод информаци \*О программе\* в файл" << endl;
}

void funcProduct()
{
    ofstream f("Products.txt");
    vector <Product> prod;
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
            InPutProd(prod);
            f << "Добавление записи. Done!" << endl;
            break;
        case 1:
            RemoveProd(prod);
            f << "Удаление записи. Done!" << endl;
            break;

        case 2:
            EditProd(prod);
            f << "Редактирование записи. Done!" << endl;
            break;

        case 3:
            OutPutProd(f, prod);
            f << "Вывод в файл. Done!" << endl;
            break;

        case 4:
            SortProd(prod);
            f << "Сортировка. Done!" << endl;
            break;
        case 5:
            AboutProgProd(f);
            break;
        case 6:
            break;

        default:
            cout << "Error" << endl;
        }

    }while (num != 6);
}


