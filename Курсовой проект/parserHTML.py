from imp_lexer import *
from prsr import *

# список доступных кодировок
encoding = [
'utf-8',
'windows-1251',
]

def parserHTML(filename):
    characters = None
    if filename: # если имя файла корректное, то 
        for enc in encoding:
            try:
                file = open(filename, encoding=enc) # пытаемся открыть файл в разных кодировках
                characters = file.read()
                file.close()
            except (UnicodeDecodeError, LookupError): # сли ошибка, игнорируем ее
                pass
            else: # иначе выходим из цикла
                break 
    document = ""
    if characters: # если файл удалось прочитать, то
        tokens = imp_lex(characters) #лексируем файл
        if tokens: # если успешно, то
            document = parser(tokens) #парсируем файл
    if document != "": # если парсинг успешный, возвращает AST
        return document
    print("\n\033[41m{}\033[40m\n".format("Parsed not completed! Invalid File!")) # иначе выводим сообщение
    return None # и возвращает None
