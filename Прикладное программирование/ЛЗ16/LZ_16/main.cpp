#include "functions.hpp"
#include <iostream>

using namespace std;

int main()
{
    int n;
    vector <int> polInt1;
    vector <int> polInt2;
    vector <int> resInt;

    vector <double> polD1;
    vector <double> polD2;
    vector <double> resD;

    setlocale(LC_ALL, "Russian");
    cout << "Р Р°Р±РѕС‚Р° СЃ РІРµРєС‚РѕСЂРѕРј С†РµР»РѕРіРѕ С‚РёРїР°" << endl;
    cout << "Р’РІРµРґРёС‚Рµ РјР°РєСЃРёРјР°Р»СЊРЅСѓСЋ СЃС‚РµРїРµРЅСЊ РїРµСЂРІРѕРіРѕ РјРЅРѕРіРѕС‡Р»РµРЅР° ";
    cin >> n;
    input(n, polInt1);
    output(polInt1);
    cout << "Р’РІРµРґРёС‚Рµ РјР°СЃРёРјР°Р»СЊРЅСѓСЋ СЃС‚РµРїРµРЅСЊ РІС‚РѕСЂРѕРіРѕ РјРЅРѕРіРѕС‡Р»РµРЅР°: ";
    cin >> n;
    input(n, polInt2);
    resInt = sum(polInt1, polInt2);
    cout << "Sum: ";
    output(resInt);
    resInt = diva(polInt1, polInt2);
    cout << "Div: ";
    output(resInt);
    resInt = prod(polInt1, polInt2);
    cout << "Prod: ";
    output(resInt);
    resInt = my_abs(polInt1);
    cout << "My_abs: ";
    output(resInt);
    cout <<"Equal: " << my_equal(polInt1, polInt2) << endl;
    cout << "Greater then: " << gt(polInt1, polInt2) << endl;

    cout << "Р Р°Р±РѕС‚Р° СЃ РІРµРєС‚РѕСЂРѕРј РІРµС‰РµСЃС‚РІРµРЅРЅРѕРіРѕ С‚РёРїР°" << endl;
    cout << "Р’РІРµРґРёС‚Рµ РјР°РєСЃРёРјР°Р»СЊРЅСѓСЋ СЃС‚РµРїРµРЅСЊ РїРµСЂРІРѕРіРѕ РјРЅРѕРіРѕС‡Р»РµРЅР°";
    cin >> n;
    input(n, polD1);
    cout << "Р’РІРµРґРёС‚Рµ РјР°РєСЃРёРјР°Р»СЊРЅСѓСЋ СЃС‚РµРїРµРЅСЊ РІС‚РѕСЂРѕРіРѕ РјРЅРѕРіРѕС‡Р»РµРЅР°: ";
    cin >> n;
    input(n, polD2);
    resD = sum(polD1, polD2);
    cout << "Sum: ";
    output(resD);
    resInt = diva(polInt1, polInt2);
    cout << "Div: ";
    output(resInt);
    resD = prod(polD1, polD2);
    cout << "Prod: ";
    output(resD);
    resD = my_abs(polD1);
    cout << "My_abs: ";
    output(resD);
    cout <<"Equal: " << my_equal(polD1, polD2) << endl;
    cout << "Greater then: " << gt(polD1, polD2) << endl;

    return 0;
}
