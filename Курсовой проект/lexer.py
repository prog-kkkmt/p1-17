import sys
import re

def lex(characters, token_exprs, sub_token_exprs=None):
    pos = 0
    lines = None
    tokens = []
    while pos < len(characters):
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
                        text = lex(text, sub_token_exprs[0], sub_token_exprs)
                    if tag == "SCRIPT" or tag == "STYLE":
                        start = match.end(0)
                        regex = re.compile(r'<\/(script|style)>')
                        match = regex.search(characters, match.end(0))
                        if match:
                            end = match.start(0)
                            text = characters[start:end:]
                    if tag == 'COMMENT':
                        regex = re.compile(r'-->')
                        match = regex.search(characters, match.end(0))
                        if match:
                            break
                    token = (text, tag)
                    # print("\n\n")
                    # print(token, lines)
                    tokens.append(token)
                break
        if not match:
            sys.stderr.write('Illegal character: "%s" ' % (characters[pos] +  characters[pos+1] + characters[pos+2] + characters[pos+3]) + 'in pos: %s\n' % str(pos))
            sys.exit(1)
        else:
            pos = match.end(0)
    return tokens
