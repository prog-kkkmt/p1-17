// Гусятинер Л.Б., МГОТУ ККМТ, 05.05.2020
// Пример использования композиции. Структура содержит
// в качестве одного (или нескольких полей) экземпляры другой
// структуры

#include <iostream>
using namespace std;

struct Date { // дата
    // по умолчанию все поля структуры - public
    int year; // год
    int month; // месяц
    int day; // день
};

struct Saler { // Продавец
    int salerId; // Уникальное число, идентификатор (ИД) продавца
    string name; // ФИО
    string city; // Город
    double comm; // Комиссионные от 0 до 1

};

class Customer { // Заказчик
    // по умолчанию все поля класса private,
    // то есть вне кода класса не видны
public:
    int customerId; // ИД заказчика
    string name; // ФИО
    string city; // Город
    int rating; // Рейтинг (некторое число от 0 до 200)
    int salerId; // ИД обслуживающего продавца
};

struct Order { // Заказ
    int orderId; // ИД заказа
    int salerId; // ИД продавца
    int customerId; // ИД заказчика
    Date date; // Дата заказа
    double cost; // Сумма заказа
};

int main() {
    Order order;
    // создали экземпляр класса (структуры)
    //
    order.orderId = 1;
    order.salerId = 1;
    order.customerId = 1;
    order.date.year = 2019;
    order.date.month = 12;
    order.date.day = 31;
    order.cost = 125.78;

    // Отпечатаем значения
    cout << order.orderId << " " << order.salerId << " " <<
        order.customerId << " " << order.date.year << "." <<
        order.date.month << "." << order.date.day << " " << order.cost << endl;
    return 0;
}
