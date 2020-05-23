#include <iostream>
#include "Costing.hpp"
#include "Release.hpp"
#include "CostItems.hpp"
#include "Products.hpp"


using namespace std;

int main()
{
    int num;
    setlocale(LC_ALL, "Russian");
    cout << "Введите номер таблицы для работы с ней:" << endl;
    cout << "0: Статьи затрат (Код статьи, Название)" << endl;
    cout << "1: Изделия (Код изделия, Название)" << endl;
    cout << "2: Калькуляция (Код калькуляции, Код изделия, Код статьи, сумма)" << endl;
    cout << "3: План выпуска (Код плана, Код изделия, Количество)" << endl;
    cout << "4: Выход" << endl;

    ofstream html("Costing.html");
    html << "<!DOCTYPE html>"<< endl << "<html>" << endl;
    html << "<head>" << endl << "<title>Калькуляция </title>" << endl;
    html << "<link rel= \"stylesheet\" href=\"style.css\">" << endl;
    html << "</head>"<< endl;
    html << "<body>" << endl;

    do{
        cout << "Введите номер таблицы для работы с ней: ";
        cin >> num;

        switch(num)
        {
        case 0:
            funcCostItem();
            break;
        case 1:
            funcProduct();
            break;
        case 2:
            funcCosting();
            break;
        case 3:
            funcRelease();
            break;
        case 4:
            cout << "Goodbye";
            break;
        default:
            cout << "Error" << endl;
        }
    }while(num != 4);

    html.open("Costing.html", ios_base::app);
    html << "</body>" << endl << "</html>" << endl;
    return 0;
}
