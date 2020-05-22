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
        cout<<"�� ������� ��������� ������� "<<Game[k].name<<"? ";
        cin.get(c);
    }while(!(c=='y' || c=='Y' || c=='n' || c=='N'));
    if(c=='y' || c=='Y'){
			Game[k].ready = true;
        cout<<"���, �� ����� ������� "<<Game[k].name<<" ����������! \n";
    }
    else
		cout<<"�� ���������� ��������� �������"<<Game[k].name<<"\n";
}

void FindGameObjects::print(){
    cout<<"name\tx\ty\tz\n";
    for(int i=0; i<10; i++)
        cout<<Game[i].name<<"\t"<<Game[i].x<<"\t"<<Game[i].y<<"\t"<<Game[i].z<<"\n";
}

void person::go(){
    int temp;
    srand(time(0));
    temp = 0 + rand() % 6;
    if(temp==0)
        x+=speed;
    else if(temp==1)
        x-=speed;
    else if(temp==2)
        y+=speed;
    else if(temp==3)
        y-=speed;
    else if(temp==4)
        z+=speed;
    else if(temp==5)
        z-=speed;
    cout<<name<<" ������ ������ ��� ���������� = "<<x<<' '<<y<<' '<<z<<endl;
}

bool archer::damage(Move obj){
    float k = fabs(x-obj.x) + fabs(y-obj.y) + fabs(z-obj.z);
    if(k<=3){
        cout<<"�� ���� ����� ��������! ��� - ����� ����";
        return false;
    }
    return true;
}

bool khith::damage(Move obj){
    float k = fabs(x-obj.x) + fabs(y-obj.y) + fabs(z-obj.z);
    if(k<=1.5){
        cout<<"�� ���� ����� �������! ��� - ����� ����";
        return false;
    }
    return true;
}

void menu(Move obj, FindGameObjects obj2, archer obj3, khith obj4) {
    bool On = true;
    int action;
    while (On) {
        cout << "�������:\n" << "1: ��� ������������ ������\n" << "2: ��� ����������� �����\n" << "3: ��� ����������� �����\n" << "4: ��� ����������� ������\n" << "5: ��� ����������� �����\n" << "6: ��� ����������� ����\n" << "7: ���������� � ��������������� ���������\n" << "8: � ���������\n" << "9: �����\n0: ����� ��������� ���������" << endl;
        cin >> action;
        switch(action) {
            case 1: system("cls"); obj.go_forward(); obj2.GameObjectsReact(obj); obj3.go(); Sleep(999); obj4.go(); On=(obj3.damage(obj) && obj4.damage(obj)); break;
            case 2: system("cls"); obj.go_back();obj2.GameObjectsReact(obj); obj3.go(); Sleep(999); obj4.go();obj4.go(); On=(obj3.damage(obj) && obj4.damage(obj)); break;
            case 3: system("cls"); obj.go_left();obj2.GameObjectsReact(obj); obj3.go(); Sleep(999); obj4.go();obj4.go(); On=(obj3.damage(obj) && obj4.damage(obj)); break;
            case 4: system("cls"); obj.go_right();obj2.GameObjectsReact(obj); obj3.go(); Sleep(999); obj4.go();obj4.go(); On=(obj3.damage(obj) && obj4.damage(obj)); break;
            case 5: system("cls"); obj.go_up();obj2.GameObjectsReact(obj); obj3.go(); Sleep(999); obj4.go();obj4.go(); On=(obj3.damage(obj) && obj4.damage(obj)); break;
            case 6: system("cls"); obj.go_down();obj2.GameObjectsReact(obj); obj3.go(); Sleep(999); obj4.go();obj4.go(); On=(obj3.damage(obj) && obj4.damage(obj)); break;
            case 7: system("cls"); obj.out();obj2.GameObjectsReact(obj); obj3.go(); Sleep(999); obj4.go();obj4.go(); On=(obj3.damage(obj) && obj4.damage(obj)); break;
            case 8: system("cls"); about(); obj2.GameObjectsReact(obj); obj3.go(); Sleep(999); obj4.go();obj4.go(); On=(obj3.damage(obj) && obj4.damage(obj)); break;
            case 0: system("cls"); obj2.print(); break;
            case 9: On = false; break;
            default: system("cls"); cout << "������ �������� ���" << endl; break;
        }
    }
}

void about() {
    setlocale(0,"");
    fstream f("about.txt");
    if(!f.is_open()){
        cout<<"���� �� ������!";
        return;
    }
    string s;
    getline(f, s, '\n');
    cout<<s;
}
