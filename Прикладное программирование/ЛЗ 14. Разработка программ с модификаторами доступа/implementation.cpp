#include "declaration.h"
Move::Move() {
    x = 0.0;
    y = 0.0;
    z = 0.0;
    step = 1.5;
}

Move::Move(double _x, double _y, double _z, double _step) {
    x = _x;
    y = _y;
    z = _z;
    step = _step;
}

void Move::out() {
    cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nstep: " << step << endl;
    cout << endl;
}

void Move::go_forward() {
    z += step;
}

void Move::go_back() {
    z -= step;
}

void Move::go_left() {
    x -= step;
}

void Move::go_right() {
    x += step;
}

void Move::go_up() {
    y += step;
}

void Move::go_down() {
    y -= step;
}

void FindGameObjects::GameObjectsReact(Move obj){
	for(int i=0; i<10; i++)
		if((obj.x == Game[i].x && obj.y == Game[i].y && obj.z == Game[i].z) && !Game[i].ready){
            Reatcs(i);
            break;
		}
};

void FindGameObjects::Reatcs(int k){
	char c;
    setlocale(0,"");
    do{
        cin.get(c);
        cout<<"Вы желаете подобрпть предмет "<<Game[k].name<<"? ";
        cin.get(c);
    }while(!(c=='y' || c=='Y' || c=='n' || c=='N'));
    if(c=='y' || c=='Y'){
			Game[k].ready = true;
        cout<<"ура, вы нашли предмет "<<Game[k].name<<" поздрвляем! \n";
    }
    else
		cout<<"вы отказались подбирать предмет"<<Game[k].name<<"\n";
}

void FindGameObjects::print(){
    cout<<"name\tx\ty\tz\n";
    for(int i=0; i<10; i++)
        cout<<Game[i].name<<"\t"<<Game[i].x<<"\t"<<Game[i].y<<"\t"<<Game[i].z<<"\n";
}

void menu(Move obj, FindGameObjects obj2) {
    bool On = true;
    int action;
    while (On) {
        cout << "Введите:\n" << "1: Для передвижения вперед\n" << "2: Для перемещения назад\n" << "3: Для перемещения влево\n" << "4: Для перемещения вправо\n" << "5: Для перемещения вверх\n" << "6: Для перемещения вниз\n" << "7: Информация о местонахождении персонажа\n" << "8: О программе\n" << "9: Выход\n0: Вывод координат предметов" << endl;
        cin >> action;
        switch(action) {
            case 1: system("cls"); obj.go_forward(); obj2.GameObjectsReact(obj); break;
            case 2: system("cls"); obj.go_back();obj2.GameObjectsReact(obj); break;
            case 3: system("cls"); obj.go_left();obj2.GameObjectsReact(obj); break;
            case 4: system("cls"); obj.go_right();obj2.GameObjectsReact(obj); break;
            case 5: system("cls"); obj.go_up();obj2.GameObjectsReact(obj); break;
            case 6: system("cls"); obj.go_down();obj2.GameObjectsReact(obj); break;
            case 7: system("cls"); obj.out();obj2.GameObjectsReact(obj); break;
            case 8: system("cls"); about(); obj2.GameObjectsReact(obj); break;
            case 0: system("cls"); obj2.print(); break;
            case 9: On = false; break;
            default: system("cls"); cout << "Такого действия нет" << endl; break;
        }
    }
}

void about() {
    setlocale(0,"");
    fstream f("about.txt");
    if(!f.is_open()){
        cout<<"Файл не открыт!";
        return;
    }
    string s;
    getline(f, s, '\n');
    cout<<s;
}

///Выполнила: Фролова Л.А.
