#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
#include <fstream>
#include "tokens.hpp"
#include "lexer.hpp"
#define size 1000

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream in;
    ofstream out;
    FILE *f = fopen("program.txt", "r");//чтение файла program.txt
    char code[size];
    fgets(code, size, f);

    out.open("token_list.txt");//создание файла token_list.txt
    Lexer lex(code);//запуск функции lex класса Lexer
    for (auto token = lex.next();
         not token.is_one_of(Token::Tokens::End, Token::Tokens::Unexpected);
         token = lex.next())
         /*
         Определяем символ при помощи next()
         При помощи is_one_of() проверяем новый токен на символ конца файла и неизвестный символ
         И если таких токенов нет проверяем символы дальше
         */
    {
        cout << setw(12) << token.tokens() << " [" << token.lexeme() << "]\n";
        out << setw(12) << token.tokens() << " [" << token.lexeme() << "]\n";
    }
    cout << "Записано в файл token_list.txt";
    //Выводим полученный результат в файл и окно консоли
}