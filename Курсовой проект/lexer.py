import re

def lex(characters, token_exprs, sub_token_exprs=None):
    pos = 0
    lines = None
    tokens = []
    while pos < len(characters):
        l = 0
        match = None
        for token_expr in token_exprs:
            # print(token_exprs)
            #print()
            pattern, tag = token_expr
            # print('pattern' + pattern)
            # print('pos = ' + str(pos), 'char ' + characters[pos])
            regex = re.compile(pattern)
            # print(regex)
            match = regex.match(characters, pos)
            # print(match)
            if match:
                # print('match' + match)
                text = match.group(0)
                if tag:
                    # print(text, tag)
                    if (tag == "TAG" or tag == "CLOSE_TAG" or tag == "OPEN_TAG") and sub_token_exprs:
                        (text, l) = lexTag(text, sub_token_exprs[0])
                        # print(l)
                    if tag == "SCRIPT" or tag == "STYLE":
                        start = match.end(0)
                        regex = re.compile(r'<\/(script|style)>')
                        match = regex.search(characters, match.end(0))
                        if match:
                            end = match.start(0)
                            text = characters[start:end:]
                        l = text.count('\n')
                    if tag == 'COMMENT':
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
                    # print("\n\n")
                    # print(token)
                    tokens.append(token)
                    for i in range(l):
                        tokens.append(('\n', 'LINE'))
                        # print(('\n', 'LINE'))
                break
        if not match:
            print("\n\033[41m{}\033[40m".format('Illegal character: "%s" ' % (characters[pos:pos+10:]) + 'in pos: %s' % str(pos)))
            return None
        else:
            pos = match.end(0)
    return tokens

def lexTag(characters, token_exprs):
    pos = 0
    lines = 0
    tokens = []
    while pos < len(characters):
        match = None
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
                        token = (text, tag)
                        tokens.append(token)
                break
        if not match:
            print("\n\033[41m{}\033[40m".format('Invalid tag: "%s" ' % (characters[pos:pos+10:]) + 'in pos: %s' % str(pos)))
            return None
        else:
            pos = match.end(0)
    return (tokens, lines)