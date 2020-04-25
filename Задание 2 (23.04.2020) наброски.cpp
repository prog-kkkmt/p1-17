#include<iostream>
using namespace std;


#define N 10

void counter(int*, int);
int sum(int*, int);
int search_max(int*, int);
void print_mas(int*, int);

 int main(void) {
	setlocale(0, "");

	int mas[N];
	int *first_element = mas; // указатель изначально указывает на первый элемент массива.
	counter(first_element, N);
	cout << "Сумма = " << sum(first_element, N) << endl;
	cout << "Макс эл-нт = " << search_max(first_element, N) << endl;
	cout << endl;
	print_mas(first_element, N);
	cout << endl;

}


void counter(int *start, int count) {
	cout << "массив:\n";
	for (int i = 0; i < count; i++) {
		int temporary_element;
		cin >> temporary_element;
		start[i] = temporary_element;
	}
}

int sum(int *start, int count){
	int result = 0;
	for (int i = 0; i < N; i++)
		result += start[i];
	return result;
}

int search_max(int *start, int count){
	int result = start[0];
	for (int i = 0; i < N; i++)
		if (result <= start[i])
			result = start[i];
	return result;
}

void print_mas(int *start, int count) {
	cout << "Вывод массива: ";
	for (int i = 0; i < N; i++){
		cout << start[i];
		if (i == N - 1)
			cout << '.' << endl;
		else
			cout << ',';
	}

}
