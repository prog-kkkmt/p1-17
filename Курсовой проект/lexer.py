import re

# функция лексинга файла
def lex(characters, token_exprs, sub_token_exprs=None):
    """
    Функция лексинга HTML документа

    Args:
        characters: Текст файла.
        token_exprs: Токены в виде регулярных выражений
        sub_token_exprs: Токены в виде регулярных выражений для тегов

    Returns:
        tokens: Список токенов в виде ((text), tag).

    Raises:
        
    """
    pos = 0
    lines = None
    tokens = []
    while pos < len(characters): # пока позиция меньше длина файла
        l = 0
        match = None
        # извлекаем из списка паттернов паттерны по одному и проверяет 
        # подходит ли
        for token_expr in token_exprs: 
            pattern, tag = token_expr
            regex = re.compile(pattern)
            match = regex.match(characters, pos)
            if match: # если нашли соответствие, то
                text = match.group(0) # получает найденный текст
                # если теги, то лексируем их отдельно
                if tag: # в зависимости от тега, разные действия
                    if (tag == "TAG" or \
                        tag == "CLOSE_TAG" or \
                        tag == "OPEN_TAG") and \
                        sub_token_exprs:
                        (text, l) = lexTag(text, sub_token_exprs[0]) 
                    # если скрипты и стили, то ищем закрывающий тег и 
                    # получаем их контент
                    if tag == "SCRIPT" or tag == "STYLE": 
                        start = match.end(0)
                        regex = re.compile(r'<\/(script|style)>')
                        match = regex.search(characters, match.end(0))
                        if match:
                            end = match.start(0)
                            text = characters[start:end:]
                        l = text.count('\n')
                    if tag == 'COMMENT': # игнориируем комменты
                        regex = re.compile(r'-->')
                        start = match.end(0)
                        match = regex.search(characters, start)
                        if match:
                            end = match.start(0)
                            text = characters[start:end:]
                            l = text.count('\n')
                            for i in range(l):
                                tokens.append(('\n', 'LINE'))

                            break
                    token = (text, tag)
                    tokens.append(token)
                    for i in range(l):
                        # добавляем все строки, которые находим в файле
                        tokens.append(('\n', 'LINE')) 
                break
        # если не находим, то выводим ошибку о незарегистрированном символе
        if not match: 
            print("\n\033[41m{}\033[40m\n".format('Illegal character: "%s" ' % (characters[pos]) + 'in pos: %s' % str(pos)))
            return None
        else:
            pos = match.end(0)
    return tokens # возвращаем токены

def lexTag(characters, token_exprs):
    """
    функция лексинга тегов

    Args:
        characters: Текст файла.
        token_exprs: Токены в виде регулярных выражений

    Returns:
        tokens: Список токенов в виде ((text), tag).

    Raises:
        
    """
    pos = 0
    lines = 0
    tokens = []
    # пока позиция меньше длины текста
    while pos < len(characters): 
        match = None
        # извлекаем по одному паттерны и ищем соответствия
        for token_expr in token_exprs: 
            pattern, tag = token_expr
            regex = re.compile(pattern)
            match = regex.match(characters, pos)
            if match:
                text = match.group(0)
                if tag:
                    if tag == 'LINE':
                        lines += 1
                    else:
                        # если находим то добавляем в список
                        token = (text, tag) 
                        tokens.append(token)
                break
        if not match: # если нет, то выводим ошибку
            print("\n\033[41m{}\033[40m".format('Invalid tag: "%s" ' % (characters[pos:pos+10:]) + 'in pos: %s' % str(pos)))
            return None
        else:
            pos = match.end(0)
    return (tokens, lines)
