import lexer

# список всех элементов языка
TAG           = 'TAG'
OPEN_TAG      = 'OPEN_TAG'
CLOSE_TAG     = 'CLOSE_TAG'
TYPE          = 'TYPE'
CONTENT       = 'CONTENT'
SCRIPT        = 'SCRIPT'
STYLE         = 'STYLE'
COMMENT       = 'COMMENT'
LINE          = 'LINE'

TAG_NAME      = 'TAG_NAME'
ATRIBUTE      = 'ATRIBUTE'
ATRIBUTE_NAME = 'ATRIBUTE_NAME'
VALUE         = 'VALUE'

# список токенов в виде регулярных выражений
token_exprs = [
    (r'[ \t]+',                                             None),
    (r'\n',                                                 LINE),
    (r'<!--',                                               COMMENT),
    (r'<script( |\n)*([-\w;: ]+(=(")?[^>]*(")?)?)*(( )?/)?>',         SCRIPT),
    (r'<style( |\n)*([-\w;: ]+(=(")?[^>]*(")?)?)*(( )?/)?>',          STYLE),
    (r'<\/[\w-]*>',                                           CLOSE_TAG),
    (r'<!DOCTYPE [ \w.:\/\-\"]+>',                     TYPE),
    (r'(([^<>\s])|( )|( )|( )|( ))+',                                     CONTENT),
    (r'<((area)|(base)|(br)|(col(?!g))|(command)|(embed)|(hr)|(img)|(input)|(keygen)|(link)|(meta)|' + 
        r'(param)|(source)|(track)|(wbr))( |\n)*([-\w;: ]+(=(")?[^>]*(")?)?)*(( )?/)?>', TAG),
    (r'<([\w-]+)( |\n)*([-\w;: ]+(=(")?[^>]*(")?)?)*(( )?/)?>',       OPEN_TAG),    
]

# токены для тегов
token_tag = [
	[
		(r'[ \t<>/]+',           None),
        (r'\n',                   LINE),
    	(r'(?<=<)[\w-]+',             TAG_NAME),
        (r'(?<=</)[\w-]+',             TAG_NAME),
        (r'["\w;:-]+(=("|\')?[^\'"]*("|\')?)?', ATRIBUTE),
    ],
]

# функция лексинга файла, передаем в нее все токены
def imp_lex(characters):
    return lexer.lex(characters, token_exprs, token_tag)