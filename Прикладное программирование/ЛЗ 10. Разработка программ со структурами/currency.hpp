#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>

using namespace std;

struct Currency {
    int ID;
    string name;
    double course;
};

void print(vector <Currency> cur) {
    system("cls");
    for (int i = 0; i < cur.size(); i++) {
        cout << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
    }

    cout << endl << "����� �������. �����" << endl;
    getch();
}

void add(vector <Currency>& cur) {
    system("cls");

    Currency buff;

    buff.ID = cur.back().ID + 1;

    cout << "������� �������� ������: ";
    cin >> buff.name;

    cout << "������� ���� � �����: ";
    cin >> buff.course;

    cur.push_back(buff);

    ofstream out("currency.txt"); // �������� ���� ��� ������

    if (out.is_open())
    {
        for (int i = 0; i < cur.size(); i++) {
            out << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
        }

        cout << endl << "���������.\n����� �������. �����" << endl;
        getch();
    } else {
        cout << endl << "������.\n����� �������. �����" << endl;
        getch();
    }

    out.close();     // ��������� ����
}

void deleteRow(vector <Currency>& cur) {
    system("cls");
    int id;
    cout << "������� ID ���������� ��������: ";
    cin >> id;

    for (int i = 0; i < cur.size(); i++) {
        if (cur.at(i).ID == id) {
            cur.erase(cur.begin() + i);
            break;
        }
    }

    ofstream out("currency.txt"); // �������� ���� ��� ������

    if (out.is_open())
    {
        for (int i = 0; i < cur.size(); i++) {
            out << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
        }

        cout << endl << "�������.\n����� �������. �����" << endl;
        getch();
    } else {
        cout << endl << "������.\n����� �������. �����" << endl;
        getch();
    }

    out.close();     // ��������� ����
}

void edit(vector <Currency>& cur) {
    system("cls");
    int id;
    bool edit = false;
    string newName;
    double newCourse;
    cout << "������� ID �������������� ��������: ";
    cin >> id;

    for (int i = 0; i < cur.size(); i++) {
        if (cur.at(i).ID == id) {
            cout << endl << "�������� ������ (" << cur.at(i).name << ". ��� ��������� - 0): ";
            cin >> newName;
            cur.at(i).name = (newName != "0") ? newName : cur.at(i).name;
            if (newName != "0") edit = true;

            cout << endl << "���� ������ (" << cur.at(i).course << ". ��� ��������� - 0): ";
            cin >> newCourse;
            cur.at(i).course = (newCourse != 0) ? newCourse : cur.at(i).course;
            if (newCourse != 0) edit = true;
        }
    }

    ofstream out("currency.txt"); // �������� ���� ��� ������

    if (out.is_open())
    {
        if (edit){
            for (int i = 0; i < cur.size(); i++) {
                out << cur.at(i).ID << '\t' << cur.at(i).name << "\t\t" << cur.at(i).course << endl;
            }

            cout << endl << "��������.\n����� �������. �����" << endl;
            getch();
        } else {
            cout << endl << "��������� ���.\n����� �������. �����" << endl;
            getch();
        }
    } else {
        cout << endl << "������.\n����� �������. �����" << endl;
        getch();
    }

    out.close();     // ��������� ����
}
