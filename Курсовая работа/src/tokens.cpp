#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
#include "tokens.hpp"

using namespace std;

//Реализация функций из файла tokens.hpp

void Token::lexeme(string_view lexeme) noexcept
{
    o_lexeme = move(lexeme); //move перемещает значение переменной вместо копирования
}

bool Token::is(Tokens tokens) const noexcept 
{ 
    return o_tokens == tokens; 
}

bool Token::is_not(Tokens tokens) const noexcept 
{ 
    return o_tokens != tokens; 
}

bool Token::is_one_of(Tokens t1, Tokens t2) const noexcept 
{ 
    return is(t1) || is(t2); 
}

template <typename... Ts> //шаблон для функции is_one_of
bool Token::is_one_of(Tokens t1, Tokens t2, Ts... ts) const noexcept
{
    return is(t1) || is_one_of(t2, ts...);
}

string_view Token::lexeme() const noexcept 
{ 
    return o_lexeme; 
}

Token::Tokens Token::tokens() const noexcept 
{ 
    return o_tokens; 
}