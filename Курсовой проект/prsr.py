from prsr_driver import *
import sys

# функция получает токены из лексера в виде ((text), tag)
def parser(tokens):
    buff = []
    level = 0
    err = []
    lines = 1
    doc = Node() # создаем объект дерева
    for token in tokens: # извлекаем по одному токееу из списка
        # в зависимости от токена, создаем нужный объект и добавляем в дерево
        if token[1] == 'OPEN_TAG':
            tag = Tag(token[0], lines) # создание объекта тега
            doc._addItem(level, tag) # добавление в дерево
            buff.append(tag) # добавление в список тега, чтобы отслеживать закрывающиеся
            level += 1 # добавление уровня вложенности
        elif token[1] == 'CLOSE_TAG':
            if buff[-1].tagName() == token[0][0][0]: # проверка закрывающихся тегов
                buff.pop()
                level -= 1 # убавление уровня вложенности
            else:
                
                while buff[-1].tagName() != token[0][0][0]: # если предыдущий тег не был закрыт, то ищем ближайший подходящий тег к текущему тегу и
                    err.append((buff[-1].name + buff[-1]._getIdentyAtrs(), buff[-1].line)) #  из неподходящих делаем список ошибок
                    buff.pop()
                    level -= 1
                    
                buff.pop()
                level -= 1
        else:
            if token[1] == 'TAG':
                doc._addItem(level, Tag(token[0], lines, is_need_close_tag=False)) # создаем элемент тега без закрыващегося тега
            elif token[1] == 'SCRIPT':
                doc._addJS(token[0]) # добавляем элемент скрипта
                doc._addItem(level, Tag([['script']], lines))
            elif token[1] == 'STYLE': # добавляем элемент стилей
                doc._addCSS(token[0]) 
                doc._addItem(level, Tag([['style']], lines))
            elif token[1] == 'TYPE': # добавление типа файла
                doc._setType(token[0])
            elif token[1] == 'LINE': # счетчик строк
                lines += 1
            else:
                doc._addItem(level, Text(token[0])) # добавление контена тега

    doc._setSize(lines) # добавление размера файла в строках
    for item in buff:
        err.append((item.name + item._getIdentyAtrs(), item.line)) # создание списка ошибок
    doc._addWarnings(err) # добавление списка ошибок в объект дерева
    return (doc, (len(err), err)) # возвращаем дерево
