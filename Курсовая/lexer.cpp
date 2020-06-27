#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
#include "tokens.hpp"
#include "lexer.hpp"

//Функция lexema() возвращающая полученный символ
Token Lexer::lexema(Token::Tokens tokens) noexcept
{
    return Token(tokens, p_cod++, 1);
}

//Функция next() сопоставляет символ с таблицей 
//и возвращает имя токена
Token Lexer::next() noexcept
{
    //Пока символ не пробел проверяем его
    while (is_space(peek()))
        get();

    switch (peek())
    {
    case '\0':
        return Token(Token::Tokens::End, p_cod, 1);
    default:
        return lexema(Token::Tokens::Unexpected);
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
        return identifier();
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return number();
    case '(':
        return lexema(Token::Tokens::LeftParen);
    case ')':
        return lexema(Token::Tokens::RightParen);
    case '[':
        return lexema(Token::Tokens::LeftSquare);
    case ']':
        return lexema(Token::Tokens::RightSquare);
    case '{':
        return lexema(Token::Tokens::LeftCurly);
    case '}':
        return lexema(Token::Tokens::RightCurly);
    case '<':
        return lexema(Token::Tokens::LessThan);
    case '>':
        return lexema(Token::Tokens::GreaterThan);
    case '=':
        return lexema(Token::Tokens::Equal);
    case '+':
        return lexema(Token::Tokens::Plus);
    case '-':
        return lexema(Token::Tokens::Minus);
    case '*':
        return lexema(Token::Tokens::Asterisk);
    case '/':
        return lexema(Token::Tokens::Slash);
    case '#':
        return lexema(Token::Tokens::Sharp);
    case '.':
        return lexema(Token::Tokens::Dot);
    case ',':
        return lexema(Token::Tokens::Comma);
    case ':':
        return lexema(Token::Tokens::Colon);
    case ';':
        return lexema(Token::Tokens::Semicolon);
    case '\'':
        return lexema(Token::Tokens::SingleQuote);
    case '"':
        return lexema(Token::Tokens::DoubleQuote);
    case '|':
        return lexema(Token::Tokens::Pipe);
    case '&':
        return lexema(Token::Tokens::Ampersand);
    case '@':
        return lexema(Token::Tokens::Dog);
    }
}

//Проверка на идентификатор и вызов функции is_identifier_char()
Token Lexer::identifier() noexcept
{
    const char *start = p_cod;
    get();
    while (is_identifier_char(peek()))
        get();
    return Token(Token::Tokens::ID, start, p_cod);
}

//Проверка на число и вызов функции is_digit()
Token Lexer::number() noexcept
{
    const char *start = p_cod;
    get();
    while (is_digit(peek()))
        get();
    return Token(Token::Tokens::Number, start, p_cod);
}

//Проверка на пробелы таюы и переходы строки
bool is_space(char c) noexcept
{
    switch (c)
    {
    case ' ':
    case '\t':
    case '\r':
    case '\n':
        return true;
    default:
        return false;
    }
}

//Проверка на число
bool is_digit(char c) noexcept
{
    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return true;
    default:
        return false;
    }
}

//Проверка на идентификатор
bool is_identifier_char(char c) noexcept
{
    switch (c)
    {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z':
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '_':
        return true;
    default:
        return false;
    }
}

//Перегруженный оператор вывода для работы с именами токенов
ostream &operator<<(ostream &os, const Token::Tokens &tokens)
{
    static const char *const names[]{
        "Number",
        "ID",
        "LeftParen",
        "RightParen",
        "LeftSquare",
        "RightSquare",
        "LeftCurly",
        "RightCurly",
        "LessThan",
        "GreaterThan",
        "Equal",
        "Plus",
        "Minus",
        "Asterisk",
        "Slash",
        "Dot",
        "Comma",
        "Colon",
        "Semicolon",
        "SingleQuote",
        "DoubleQuote",
        "Pipe",
        "End",
        "Sharp",
        "Dog",
        "Ampersand",
    };
    return os << names[static_cast<int>(tokens)];
}
