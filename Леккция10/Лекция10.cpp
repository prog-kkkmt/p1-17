#include<iostream>
#include <cstring>
/**Вывести дату в виде дд.мм.гг в строковую форму**/
using namespace std;
/**По правилам, дата прописью записывается следующим образом:

21.05.1972 - Двадцать первое мая одна тысяча девятсот семьдесят второго года. Реализуйте эту функцию.**/
void printdate(string str){
	setlocale(0,"");
	int i=0;
	int k=0;
	int date[3]={0,0,0};
	for(int i=0; str[i]!='\0'; i++)
	{
		if(isdigit(str[i]))
            date[k]=date[k]*10 + str[i]-'0';
        if(str[i]=='.')
            k++;
	}
	cout<<date[0]<<" "<<date[1]<<" "<<date[2];
	switch(date[0]){
		case 1: cout<<"Первое "; break;
		case 2: cout<<"Второе "; break;
		case 3: cout<<"Третье "; break;
		case 4: cout<<"Четвертое "; break;
		case 5: cout<<"Пятое "; break;
		case 6: cout<<"Шестое "; break;
		case 7: cout<<"Седьмое "; break;
		case 8: cout<<"Восьмое "; break;
		case 9: cout<<"Девятое "; break;
		case 10: cout<<"Десятое "; break;
		case 11: cout<<"Одиннадцатое "; break;
		case 12: cout<<"Двенадцатое "; break;
		case 13: cout<<"Тринадцатое "; break;
		case 14: cout<<"Четырнадцатое "; break;
		case 15: cout<<"Пятнадцатое "; break;
		case 16: cout<<"Шестнадцатое "; break;
		case 17: cout<<"Семнадцатое "; break;
		case 18: cout<<"Восемнадцатое "; break;
		case 19: cout<<"Девятнадцатое "; break;
		case 20: cout<<"Двадцатое "; break;
		case 21: cout<<"Двадцать первое "; break;
		case 22: cout<<"Двадцать второе "; break;
		case 23: cout<<"Двадцать третье "; break;
		case 24: cout<<"Двадцать четвертое "; break;
		case 25: cout<<"Двадцать пятое "; break;
		case 26: cout<<"Двадцать шестое "; break;
		case 27: cout<<"Двадцать седьмое "; break;
		case 28: cout<<"Двадцать восьмое "; break;
		case 29: cout<<"Двадцать девятое "; break;
		case 30: cout<<"Тридцатое "; break;
		case 31: cout<<"Тридцать первое "; break;
	}
	switch (date[1]){
		case 1: cout<<"Января "; break;
		case 2: cout<<"Февраля "; break;
		case 3: cout<<"Марта "; break;
		case 4: cout<<"Апреля "; break;
		case 5: cout<<"Мая "; break;
		case 6: cout<<"Июня "; break;
		case 7: cout<<"Июля"; break;
		case 8: cout<<"Августа "; break;
		case 9: cout<<"Сентября "; break;
		case 10: cout<<"Октября "; break;
		case 11: cout<<"Ноября "; break;
		case 12: cout<<"Декабря "; break;
	}
	switch (date[2]/1000){
		case 1: cout<<"Одна тысяча "; break;
		case 2: cout<<"Две тысячи "; break;
	}
	switch (date[2]/100%10){
		case 1: cout<<"Сто "; break;
		case 2: cout<<"Двести " ; break;
		case 3: cout<<"Триста "; break;
		case 4: cout<<"Четыреста "; break;
		case 5: cout<<"Пятьсот "; break;
		case 6: cout<<"Дшестьсот "; break;
		case 7: cout<<"Семьсот "; break;
		case 8: cout<<"Восемьсот "; break;
		case 9: cout<<"Девятьсот "; break;
	}
	int temp =  date[2]%100;
	if(temp>20 && temp%10!=0){
		switch(temp/10){
			case 2: cout<<"Двадцать "; break;
			case 3: cout<<"Тридцать "; break;
			case 4: cout<<"Сорок "; break;
			case 5: cout<<"Пятьдесят "; break;
			case 6: cout<<"Шестдесят "; break;
			case 7: cout<<"Седмьдесять "; break;
			case 8: cout<<"Восемдесят "; break;
			case 9: cout<<"Девяносто "; break;
		}
		switch(temp%10){
			case 1: cout<<"Первого "; break;
			case 2: cout<<"Второго "; break;
			case 3: cout<<"Третьего "; break;
			case 4: cout<<"Четвертого "; break;
			case 5: cout<<"Пятого "; break;
			case 6: cout<<"Шестого "; break;
			case 7: cout<<"Седьмого "; break;
			case 8: cout<<"Восьмого "; break;
			case 9: cout<<"Девятого "; break;
		}
	}
	else
	{
		switch(temp){
			case 1: cout<<"Первое "; break;
			case 2: cout<<"Второе "; break;
			case 3: cout<<"Третье "; break;
			case 4: cout<<"Четвертое "; break;
			case 5: cout<<"Пятое "; break;
			case 6: cout<<"Шестое "; break;
			case 7: cout<<"Седьмое "; break;
			case 8: cout<<"Восьмое "; break;
			case 9: cout<<"Девятое "; break;
			case 10: cout<<"Десятое "; break;
			case 11: cout<<"Одиннадцатое "; break;
			case 12: cout<<"Двенадцатое "; break;
			case 13: cout<<"Тринадцатое "; break;
			case 14: cout<<"Четырнадцатое "; break;
			case 15: cout<<"Пятнадцатое "; break;
			case 16: cout<<"Шестнадцатое "; break;
			case 17: cout<<"Семнадцатое "; break;
			case 18: cout<<"Восемнадцатое "; break;
			case 19: cout<<"Девятнадцатое "; break;
			case 20: cout<<"Двадцатое "; break;
			case 30: cout<<"Тридцатое "; break;
			case 40: cout<<"Сороковое "; break;
			case 50: cout<<"Пятьдесятого "; break;
			case 60: cout<<"Шестьдесятого "; break;
			case 70: cout<<"Семедесятого "; break;
			case 80: cout<<"Восьмидесятого "; break;
			case 90: cout<<"Девяностого "; break;
		}
	}
	cout<<"года "
}

int main(){
cout<<"Введите строку в виде дд.мм.гггг";
string str;
cin>>str;
printdate(str);
return 0;
}

