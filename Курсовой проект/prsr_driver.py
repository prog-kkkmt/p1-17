# ***** CLASSES *****

class Text:
	def __init__(self, text):
		self.content = text
		self.parent = None
		self.level = 0
		self.levels = []


	def __repr__(self):
		return self.content

# Tag
class Tag:
	def __init__(self, args, line, is_need_close_tag = True):
		# global styles
		self.content = []
		self.parent = None
		self.level = 0
		self.levels = []
		self.line = line
		self.name = args[0][0]
		self.atrs = {}
		self.style = {}
		# if '*' in styles:
		# 	self.style.update(styles['*'])
		# if self.name in styles:
		# 	self.style.update(styles[self.name])
		self.is_need_close_tag = is_need_close_tag
		for atr in args[1:]: 
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

		#               **** STYLES ****
		# if self.name == "link" and "rel" in self.atrs:
		# 	if self.atrs["rel"] == "stylesheet":
		# 		styles = updateDict(styles, getStyle(self.atrs["href"]))


	def __repr__(self):
		# print(self.name, self.level, self.levels)
		tabs = ""
		if self.level >= 1:
			tabs = ''.join(['|    ' if self.levels[i] else '     ' for i in range(self.level)])

		line = f"{self.name + self._getIdentyAtrs()}"
		# atributes
		# for atr in self.atrs:
		# 	line += f"\n{tabs}  {atr + ' : ' + self.atrs[atr]}"
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

	def _getIdentyAtrs(self):
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

	def _findBy(self, atr = None, value = None, tagName = None):
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

	def addAtribute(self, **atrs):
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

class Node:
	def __init__(self, content = None):
		self.content = []
		self.type = None
		self.JS = []
		self.CSS = []
		self.level = -1
		self.lines = 0
		self.warnings = None
		if content:
			self.content.append(content)

	def __repr__(self):
		line = ""
		for item in self.content:
			line += f"{str(item)}\n"
			# line += str(styles)
		return line

	def _setType(self, typeDOM):
		self.type = typeDOM.split(" ")[1].split(">")[0]

	def _addItem(self, level, content, tag = None, current_level = 0):
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

	def _addJS(self, content):
		self.JS.append(content)

	def _addCSS(self, content):
		self.CSS.append(content)

	def _getIdentyAtrs(self):
		return ""

	def _addWarnings(self, warnings):
		self.warnings = warnings

	def _setSize(self, lines):
		self.lines = lines
