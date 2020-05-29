#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

#include <iostream>
#include <cstring>
#include <fstream>
#include <locale>

using namespace std;

class Move {
public:
    friend class FindGameObjects;
    Move();
    Move(double _x, double _y, double _z, double _step);

    void go_forward();
    void go_back();
    void go_left();
    void go_right();
    void go_up();
    void go_down();
    void out();

private:
    double x;
    double y;
    double z;
    double step;
};

struct GameObjects{
    string name;
    float x, y, z;
    bool ready = false;
};

class FindGameObjects{
public:
    FindGameObjects(){//переписываем союбственный конструктор
       srand( time( 0 ) );
        Game = new GameObjects[10];
        for(int i=0; i<10; i++){
            Game[i].x = -2 + rand() % 5;
            Game[i].y = -2 +rand() % 5;
            Game[i].z = -2 +rand() % 5;
            Game[i].x = Game[i].x * 1.5;
            Game[i].y = Game[i].y * 1.5;
            Game[i].z = Game[i].z * 1.5;
            Game[i].name = name[i];
        }
    }
    void GameObjectsReact(Move obj);//реакция на побор предмета
    void Reatcs(int k);//действия 
    void print();//вывод
private:
    GameObjects *Game = new GameObjects[10];
    string *name = new string[10]{"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth"};
};

void menu(Move obj, FindGameObjects obj2 );
void about();
#endif // DECLARATION_H_INCLUDED
