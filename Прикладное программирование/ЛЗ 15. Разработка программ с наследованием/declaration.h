#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED

#include <iostream>
#include "windows.h"
#include <cmath>
#include <cstring>
#include <fstream>
#include <locale>

using namespace std;

class Move {
public:
    friend class FindGameObjects;
    friend class archer;
    friend class khith;
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
    FindGameObjects(){
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
    void GameObjectsReact(Move obj);
    void Reatcs(int k);
    void print();
private:
    GameObjects *Game = new GameObjects[10];
    string *name = new string[10]{"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth"};
};

class person{

public:
    person(float _x, float _y, float _z, float _speed, string _name){
        x=_x;
        y=_y;
        z=_z;
        speed=_speed;
        name = _name;
    }
    void go();
protected:
    float x,y,z;
    string name;
    float speed;

};

class archer : public person{
public:
    archer():person(-5.0, 0.0, 0.0, 1.5, "archer"){};
    bool damage(Move obj);
};

class khith : public person{
public:
    khith():person(5.0, 0.0, 0.0, 1.5, "khith"){};
    bool damage(Move obj);
};

void menu(Move obj, FindGameObjects obj2, archer obj3, khith obj4);
void about();
#endif // DECLARATION_H_INCLUDED
