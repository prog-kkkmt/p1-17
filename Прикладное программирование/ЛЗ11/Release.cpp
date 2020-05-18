/** План выпуска: Код плана, Код изделия, количество */

#include "Release.hpp"

void InPutRelease(vector <Release> &rel){
    Release buf;
    int n;
    cout << "Введите кол-во записей: ";
    cin >> n;
	for (int i = 0; i < n; i++)
	{

		cin >> buf.planCode >> buf.prodCode >> buf.quan;
        	rel.push_back(buf);
	}
}

void OutPutRelease(ofstream &f, vector <Release> &rel){
	for (unsigned i = 0; i < rel.size() ; i++)
	{
        f << rel.at(i).planCode << "\t";
        f << rel.at(i).prodCode << "\t";
        f << rel.at(i).quan << endl;
	}
	f << "________________________"<< endl;
}



void RemoveRelease(vector <Release> &rel)
{
        int m;
        int code;

        cout  << "Введите кол-во удаляемых записей: ";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cout << "Введите код плана удаляемой записи: ";
            cin  >> code;
            rel.erase(remove_if(rel.begin(), rel.end(), [code](const Release &rel){ return rel.planCode == code; }), rel.end());
        }


}

void EditRelease (vector <Release> &rel)
{
    int code;
    int num, buf;

    cout << "Введите код плана изменяемой записи: ";
    cin >> code;
    cout << "0: Код плана" << endl;
    cout << "1: Код изделия" << endl;
    cout << "2: Количество" << endl;

    for (unsigned i = 0; i < rel.size(); i++) {
        if (rel.at(i).planCode == code) {
            cin >> num;
            cin >> buf;
            switch (num) {
                case 0:
                    rel.at(i).planCode = buf;
                    break;

                case 1:
                    rel.at(i).prodCode = buf;
                    break;

                case 2:
                    rel.at(i).quan = buf;
                    break;

                default:
                     break;
            }
        }
    }
}



void SortRelease(vector <Release> &rel) // Функция сортировки по коду плана
{
    Release buff;
    int num;

    cout << "Выберите тип сортировки" << endl;
    cout << "0: По возрастанию" << endl;
    cout << "1: По убыванию" << endl;
    cin >> num;
    switch(num){
        case 0:
            for (unsigned i = 0; i < rel.size() - 1; i++)
                for (unsigned j = i; j < rel.size(); j++)
                {
                    if (rel.at(i).planCode > rel.at(j).planCode)
                    {

                        buff = rel.at(i);
                        rel.at(i) = rel.at(j);
                        rel.at(j) = buff;
                    }
                }
            break;
        case 1:
            for (unsigned i = 0; i < rel.size() - 1; i++)
                for (unsigned j = i; j < rel.size(); j++)
                {
                    if (rel.at(i).planCode < rel.at(j).planCode)
                    {

                        buff = rel.at(i);
                        rel.at(i) = rel.at(j);
                        rel.at(j) = buff;
                    }
                }
            break;
        default:
            cout << "Error!";
            break;
    }

}

void AboutProgRelease(ofstream &f)
{
    f << "План выпуска (Код плана, Код изделия, Количество)" << endl;
    f << "Источник: Экономическая информатика: лабораторный практикум / сост. О.В. Гусятинер, Л.Б. Гусятинер. – Ковров: ГОУ ВПО «КГТА имени В.А. Дегтярева», 2009" << endl;
    f << "https://nsportal.ru/sites/default/files/2020/05/05/ekon._inf.pdf" << endl;
    f << "Выполнила: Попкова Алена П1-17" << endl;
    f << "18.05.2020"<< endl;
    f << "Функции программы:  Добавление записи, Удаление записи, Редактирование записи, Печать в файл, Сортировка, Вывод информаци \*О программе\* в файл" << endl;
}

void funcRelease()
{
    ofstream f("TheReleasePlan.txt");
    vector <Release> rel;
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
            InPutRelease(rel);
            f << "Добавление записи. Done!" << endl;
            break;
        case 1:
            RemoveRelease(rel);
            f << "Удаление записи. Done!" << endl;
            break;

        case 2:
            EditRelease(rel);
            f << "Редактирование записи. Done!" << endl;
            break;

        case 3:
            OutPutRelease(f, rel);
            f << "Вывод в файл. Done!" << endl;
            break;

        case 4:
            SortRelease(rel);
            f << "Сортировка. Done!" << endl;
            break;
        case 5:
            AboutProgRelease(f);
            break;
        case 6:
            break;

        default:
            cout << "Error" << endl;
        }

    }while (num != 6);
}



