# ***** CLASSES *****

# Text
class Text:
    def __init__(self, text): # конструктор
        self.content = text # контент тега
        self.parent = None #  родительский тег
        self.level = 0 # уровень вложенности тега
        self.levels = [] # список последний ли тег на своем уровнре вложенности(для вывода дерева)


    def __repr__(self): # строковое представления объекта
        return self.content

# Tag
class Tag:
    def __init__(self, args, line, is_need_close_tag = True): # конструктор
        self.content = [] # контент тега
        self.parent = None #  родительский тег
        self.level = 0 # уровень вложенности тега
        self.levels = [] # список последний ли тег на своем уровнре вложенности(для вывода дерева)
        self.line = line # номер строки тега
        self.name = args[0][0] # имя тгеа
        self.atrs = {} # словарь атрибутов
        self.style = {} # словарь стилей
        self.is_need_close_tag = is_need_close_tag # требуется ли закрывающий тег
        for atr in args[1:]: # добавление атрибутов
            if atr[1] == "ATRIBUTE":
                atr_value = None
                if '=' in atr[0]:
                    atr_name = atr[0].split('=')[0].replace(' ', '') 
                    atr_value = atr[0].split('=')[1]
                else: 
                    atr_name = atr[0].replace(' ', '')
                if atr_value:
                    if atr_value[0] == '"' and atr_value[-1] == '"' or atr_value[0] == "'" and atr_value[-1] == "'":
                        atr_value = atr_value[1:-1]
                self.addAtribute(**{atr_name: (atr_value if atr_value else "")})

    def __repr__(self): # строковое представления объекта
        tabs = ""
        if self.level >= 1:
            tabs = ''.join(['|    ' if self.levels[i] else '     ' for i in range(self.level)])

        line = f"{self.name + self._getIdentyAtrs()}"
        for item in self.content:
            typeElem = str(type(item)).split("'")[1].split(".")
            typeElem = typeElem[1] if len(typeElem) > 1 else typeElem[0] 
            item.level = self.level + 1
            if self.content.index(item) < len(self.content) - 1:
                item.levels = [*self.levels, 1]
            else:
                item.levels = [*self.levels, 0]
            line += f"\n{tabs}|____" + '%r' % item
        self.level = 0
        self.levels = []
        return line

    def _getIdentyAtrs(self): # функция превращения атрибутов в цельную строку
        identy = ""
        if 'id' in self.atrs:
            for ids in self.atrs['id']:
                if len(ids) > 0:
                    identy += "#" + ids
        if 'class' in self.atrs:
            for classes in self.atrs['class']:
                if len(classes) > 0:
                    identy += "." + classes

        return identy

    def _findBy(self, atr = None, value = None, tagName = None): # поиск элемента по необходимым критериям
        elems = []
        for elem in self.content:
            typeElem = str(type(elem)).split("'")[1].split(".")
            typeElem = typeElem[1] if len(typeElem) > 1 else typeElem[0] 
            # print(typeElem, value)
            if typeElem == "Tag":
                if not tagName:
                    if atr in elem.atrs:
                        if value:
                            if elem.atrs[atr] == value or \
                               value in elem.atrs[atr]:
                                elems.append(elem)
                        else:
                            elems.append(elem)
                    elems.extend(elem._findBy(atr, value))
                else:
                    if elem.name == tagName:
                        elems.append(elem)
                    elems.extend(elem._findBy(tagName=tagName))
        return elems

    def addAtribute(self, **atrs): # добавить атрибуты тегу
        for atr, value in atrs.items():
            if atr == 'style':
                pass
            elif atr == "class" or atr == "id":
                self.atrs[atr].extend(value.split(" ")) if (atr in self.atrs) else self.atrs.update({atr: value.split(" ")})
            else:
                self.atrs[atr] = value
        return True

    def tagName(self):
        return self.name

# класс дерева
class Node:
    def __init__(self, content = None):
        self.content = []  # контент дерева
        self.type = None  # тип файла
        self.JS = []  # скрипты
        self.CSS = []  # стили
        self.level = -1  # уровень вложенности
        self.lines = 0  # список последний ли тег на своем уровнре вложенности(для вывода дерева)
        self.warnings = None # список ошибок
        if content: 
            self.content.append(content)

    def __repr__(self): # строковое представления объекта
        line = ""
        for item in self.content:
            line += f"{str(item)}\n"
        return line

    def _setType(self, typeDOM): # установка типа файла
        self.type = typeDOM.split(" ")[1].split(">")[0]

    def _addItem(self, level, content, tag = None, current_level = 0): # добавление элемента в дерево
        if not tag:
            tag = self
        if level == current_level:
            typeElem = str(type(content)).split("'")[1].split(".")
            typeElem = typeElem[1] if len(typeElem) > 1 else typeElem[0]

            if typeElem == "Tag":
                content.parent = tag

            tag.content.append(content)
            return tag
        tag.content[len(tag.content) - 1] = self._addItem(level, content, tag.content[len(tag.content) - 1], current_level + 1)
        return tag

    def _addJS(self, content): # добавление скриптов
        self.JS.append(content)

    def _addCSS(self, content): # добавление стилей
        self.CSS.append(content)

    def _getIdentyAtrs(self): # функция превращения атрибутов в цельную строку
        return ""

    def _addWarnings(self, warnings): # добавление списка ошибок
        self.warnings = warnings

    def _setSize(self, lines): # установка размера
        self.lines = lines
