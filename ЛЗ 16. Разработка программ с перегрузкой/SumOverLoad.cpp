// Гусятинер Л.Б. Элементарный пример перегрузки, 16.05.2020
// МГОТУ ККМТ
///
#include <iostream>
using namespace std;

int sum(int, int);
float sum(float, float);
double sum(double, double);

int main() {
    cout << sum(1, 2) << endl;
    cout << sum(1.5f, 2.0f) << endl;
    cout << sum(1.5, 2.0) << endl;
    /* А следующий код не скомпилируется. Почему ? */
    // cout << sum(1, 2.0) << endl;

    return 0;
}

int sum(int a, int b) {
    return a + b;
}

float sum(float a, float b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}
