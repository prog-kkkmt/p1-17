/**�������� ���������, ������� ��������� ����� �����.

���������: ������� ����� �1-17
��������: Stepik.org "���������������� �� ����� C++" Computer Science Center (CS �����) 1.8.10. https://stepik.org/lesson/13377/step/10
23.04.2020 **/

#include <iostream>

using namespace std;

int main(){
    int T;
    int a, b;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}
