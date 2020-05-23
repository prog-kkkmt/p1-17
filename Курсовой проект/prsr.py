from prsr_driver import *
import sys

def parser(tokens):
	buff = []
	level = 0
	err = []
	lines = 1
	doc = Node()
	for token in tokens:
		# print(token)

		if token[1] == 'OPEN_TAG':
			tag = Tag(token[0], lines)
			doc._addItem(level, tag)
			buff.append(tag)
			level += 1
		elif token[1] == 'CLOSE_TAG':
			if buff[-1].tagName() == token[0][0][0]:
				buff.pop()
				level -= 1
			else:
				# print( buff[-1])
				
				while buff[-1].tagName() != token[0][0][0]:
					err.append((buff[-1].name + buff[-1]._getIdentyAtrs(), buff[-1].line))
					buff.pop()
					level -= 1
					
				buff.pop()
				level -= 1
				# sys.stderr.write('Illegal token: %s\n' % str(token))
				# sys.exit(1)
		else:
			if token[1] == 'TAG':
				doc._addItem(level, Tag(token[0], lines, is_need_close_tag=False))
			elif token[1] == 'SCRIPT':
				doc._addJS(token[0])
				doc._addItem(level, Tag([['script']], lines))
			elif token[1] == 'STYLE':
				doc._addCSS(token[0])
				doc._addItem(level, Tag([['style']], lines))
			elif token[1] == 'TYPE':
				doc._setType(token[0])
			elif token[1] == 'LINE':
				lines += 1
			else:
				doc._addItem(level, Text(token[0]))

		# print(buff)
	# print(level, err)
	# print(lines)
	doc._setSize(lines)
	for item in buff:
		err.append((item.name + item._getIdentyAtrs(), item.line))
	doc._addWarnings(err)
	return (doc, (len(err), err))
