##  HTML PARSER V.2.3.1.610 (Count Lines, Fixed bugs, Correct output of warnings)
##  
##  DEVELOPER: OVOSKOP
##
##  COPYRIGHT. ALL RIGHT RESERVED.
##
##  CLASSES:
##      
##      TAG - Object of Tag
##      Node - Document Object Model or Node of Tags          
##
##


import sys
import os.path
import re
import inspect
import ctypes

from datetime import datetime

from parserHTML import *

kernel32 = ctypes.windll.kernel32
kernel32.SetConsoleMode(kernel32.GetStdHandle(-11), 7) # подключаем ANSI в консоль

def getDocument():
    """
    Получение AST дерева, пытаемся получить пока не получим.

    Args:

    Returns:
        document: AST дерево

    Raises:
        
    """
    filename = input("\nName of HTML file ('q' - exit): ") # получаем имя файла

    if filename == 'q': # выходим при q
        sys.exit() 
    # пока ошибки, просим еще раз ввести имя файла
    while not os.path.isfile(filename) or \
          not 'html' in filename.split('.') or \
          len(filename.split('.')) < 2: 
        if filename == 'q':
            sys.exit()
        if not 'html' in filename.split('.') or len(filename.split('.')) < 2:

            filename = input("\n\033[41m{}\033[40m\n".format("File '" + filename +"' is not HTML file.") + "\nPlease enter correct name of HTML file ('q' - exit): ")
        else:
            filename = input("\n\033[41m{}\033[40m\n".format("File '" + filename +"' is not exist.") + "\nPlease enter correct name of HTML file ('q' - exit): ")
    start_time = datetime.now()
    document = parserHTML(filename) #парсируем файл

    if document: # если успешно
        (document, (len_err, err)) = document # то получаем дерево и ошибки
        print("\n\033[42m{}\033[40m\n".format("Parsed completed!"))
        if len_err: # если есть ошибки, то выводим их
            print("\033[30m\033[43m{}\033[37m\033[40m\n".format(
                f"{len_err} warning in {','.join(' < ' + e + ' > on line ' + str(l) for (e, l) in err)}")
            )
        print(datetime.now() - start_time)
        return document # возвращаем дерево
    else:
        return None
# главное исполнение программы
if __name__ == "__main__":

    print("HTML Parser v.2.3.1.610 (released 13.05.2020). Created by OVOSKOP.")
    print('Type "help" for more information.')
    
    document = getDocument()
    while not document:
        document = getDocument() # получаем дерево
    print('\n')
    #print(document) # выводим его на экран
    