#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <iostream>
using namespace std;

class Token //класс Токенов
{
public:
    enum class Tokens //создание вложенного класса с перечислением символьных констант
    {
        Number,      //токен Число
        ID,          //токен Идентификатор
        LeftParen,   //токен Левая скобка
        RightParen,  //токен Правая скобка
        LeftSquare,  //токен Левая квадратная скобка
        RightSquare, //токен Правая квадратная скобка
        LeftCurly,   //токен Левая фигурная скобка
        RightCurly,  //токен Правая фигурная скобка
        LessThan,    //токен Меньше
        GreaterThan, //токен Больше
        Equal,       //токен Равно
        Plus,        //токен Плюс
        Minus,       //токен Минус
        Asterisk,    //токен Звездочка
        Slash,       //токен Слеш
        Dot,         //токен Точка
        Comma,       //токен Запятая
        Colon,       //токен Двоеточие
        Semicolon,   //токен Точка с запятой
        SingleQuote, //токен Одинарная кавычка
        DoubleQuote, //токен Двойная кавычка
        Comment,     //токен Комментарий
        Pipe,        //токен Вертикальная черта
        End,         //токен Конец
        Sharp,       //токен Шарп
        Dog,         //токен Собака
        Ampersand,   //токен Амперсант
        Unexpected,  //токен Неопределенный
    };
    /*
    Вместо блока try catch для обработки исключений говорим компилятору
    что функция и конструкторы исключений не обрабатывают при прмощи
    noexcept, что ускоряет компиляцию 
    */

    //Конструкторы класса Token принимают на вход массив символов и передают
    //на обработку методам класса Lexer
    Token(Tokens tokens) noexcept : o_tokens{tokens} {}
    Token(Tokens tokens, const char *cod, size_t len) noexcept : o_tokens{tokens}, o_lexeme(cod, len) {}
    Token(Tokens tokens, const char *cod, const char *end) noexcept : o_tokens{tokens}, o_lexeme(cod, distance(cod, end)) {}

    //Прототипы функций
    Tokens tokens() const noexcept;
    bool is(Tokens tokens) const noexcept;
    bool is_not(Tokens tokens) const noexcept;
    bool is_one_of(Tokens t1, Tokens t2) const noexcept;
    template <typename... Ts> //шаблон для функции is_one_of
    bool is_one_of(Tokens t1, Tokens t2, Ts... ts) const noexcept;
    string_view lexeme() const noexcept;
    void lexeme(string_view lexeme) noexcept;

private:
    Tokens o_tokens{};
    string_view o_lexeme{};
};

#endif