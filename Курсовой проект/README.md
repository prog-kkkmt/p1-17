# Интерактивный HTML-парсер
Интерактивный HTML-парсер — программа, анализирующая HTML(в планах CSS)-код и приводящая его в вид AST(Abstract Syntax Tree) - абстрактное синтаксическое дерево.

Пример (ПРИМЕР 1):

	html.html:
		<!DOCTYPE html>
		<html lang="ru">
			<head>
				<link rel="stylesheet" href="style.css">
			</head>
			<body>
				<div id="qwe">
					<a href="#" class="bad">Hello1</a>
					<div id="ast">AST 
					sCOOL</div>
				</div>
				<div class="i asd" id="i" ast="asd" req>Hello2</div>
	
			<input>
				<div class="i">Hello3</div>
			</body>
		</html>

	Результат работы парсера:

	html                                                                                                                    
	|____head                                                                                                               
	|    |____link                                                                                                          
	|____body                                                                                                                    
	|____div#qwe                                                                                                            
	|    |____a.bad                                                                                                         
	|    |    |____Hello1                                                                                                   
	|    |____div#ast                                                                                                       
	|         |____AST                                                                                                      
	|         |____sCOOL                                                                                                    
	|____div#i.i.asd                                                                                                        
	|    |____Hello2                                                                                                        
	|____input                                                                                                              
	|____div.i                                                                                                                   
	     |____Hello3 


___________________________________________________________________________________________________________________

Также он выявляет ошибки, невалидность кода. Например (ПРИМЕР 2):
	
	html.html:
		<!DOCTYPE html>
		<html lang="ru">
			<head>
				<link rel="stylesheet" href="style.css">
			</head>
			<body>
				<div id="qwe">
					<a href="#" class="bad">Hello1</a>
					<div id="ast">AST 
					sCOOL</div>
				</div>
				<div class="i asd" id="i" ast="asd" req>Hello2</div>
	
			<input>
				<div class="i">Hello3</div>
			<!-- ПРОПУЩЕН </body> --> 
		</html>

	Результат работы парсера:
	
	Parsed completed!

	1 warning!

Примеры работы с ошибками будет приведен далее.

___________________________________________________________________________________________________________________

При запуске программы (main.py) вы увидите:
	
	HTML Parser v.2.3.1.464 (released 27.04.2020). Created by OVOSKOP.                                                      
	Type "help" for more information.                                                                                    
	Name of HTML file ('q' - exit): _

Вам нужно будет указать имя HTML файла в формате {filename.html}. Если вы хотите закрыть программу на этом шаге, то наберите "q".

При успешном выполнении программы вы увидите надпись:
	
	Parsed completed!

При наличии ошибок в коде, вы увидите надпись 

	{_} warning!

с количеством ошибок.

После выполнения, AST и вся необходимая ин-фа хранится в объекте с именем "document".

После этого парсер будет ожидать комманд:

	>>> _

Список всех доступных функций вы можете посмотреть набрав комманду "help" или "help()".

Если хотите спарсировать новый файл, то наберите комманду "new" или "new()".

Чтобы закрыть программу, наберите комманду "quit" или "quit()"

___________________________________________________________________________________________________________________

Давайте разберем, как использовать комманды.

При наборе комманды "help" выходит список комманд

	{ Tag }.getInfo()                                 
	{ Tag }.innerHTML(HTML)
	{ Tag }.outerHTML(HTML)                                                                                                 
	{ Tag }.textContent(text)                                                                                               
	{ Tag }.getChild()                                                                                                      
	{ Tag }.getFirstChild()                                                                                                 
	{ Tag }.getLastChild()                                                                                                  
	{ Tag }.getParent()                                                                                                     
	{ Tag }.tagName()                                                                                                       
	{ Tag }.getAtributeValue(atributeName)                                                                                  
	{ Tag }.previousSibling()                                                                                               
	{ Tag }.nextSibling()                                                                                                   
	{ Tag }.addAtribute()                                                                                                   
	{ Tag }.appendElem(elem)                                                                                                
	{ Tag }.prependElem(elem)                                                                                               
	{ Tag }.before(elem)                      
	{ Tag }.after(elem)                       
	{ Node }.getType()                        
	{ Node }.getJS()                          
	{ Node }.getCSS()                         
	{ Node }.getElementById(idName)           
	{ Node }.getElementsByClassName(className)
	{ Node }.getElementsByTagName(tagName)    
	{ Node }.getElementsByAtribute(atr, value)
	{ Node }.getParent()                                                                                                    
	{ Node }.body()                                                                                                         
	{ Node }.documentElement()                                                                                              
	{ Node }.head()                                                                                                         
	{ Node }.createElement(name)                                                                                            
	{ Node }.getStyles()                                                                                                    
	{ Node }.tagName()                                                                                                      
	{ Node }.warnings()                                                                                                     
	new()                                                                                                                   
	quit()
	
Класс { Node } - это только "document"
Класс { Tag } - все полученные элементы(тэги).

Например:

	>>> document.nextSibling()

выдаст ошибку 
	
	Unknown command: nextSiblings

Но например:

	>>> document.warnings()

выведет все тэги, имеющие ошибки. Вернемся к примеру 2: набрав эту комманду мы получим:

	['body'] - лист с именами тэгов, имеющих ошибки

___________________________________________________________________________________________________________________

Давайте разберем поближе работу с объектом document и получим несколько тэгов кода из ПРИМЕРА 1.

Наберем:

	>>> document.getElementById(qwe)

Вывод: 
	
	div#qwe
	|____a.bad
	|    |____Hello1
	|____div#ast
	     |____AST
	     |____sCOOL

Вывел AST именно того тэга, который нам нужен. Этот элемент является объектом класса { Tag }. Теперь к нему могут быть применимы все метода этого класса. Введем: 

	>>> document.getElementById(qwe).getInfo()

Вывод:
	
	< div#qwe >
        parent: < body >
        content: <a href="#" class="bad">Hello1</a><div id="ast">AST sCOOL</div>
        atributes:
                id: ['qwe']
        style:

Все работает! Но что, если мы хотим работать непосредственно с этим тэгом? Мы можем завести для него переменную:

	 >>> item = document.getElementById(qwe)

Вывода нет, но теперь в памяти есть объект "item".

Теперь наберем:

	>>> item

Вывод:

	div#qwe
	|____a.bad
	|    |____Hello1
	|____div#ast
	     |____AST
	     |____sCOOL

Аналогично:

	>>> item.getInfo()

Вывод:
	
	< div#qwe >
        parent: < body >
        content: <a href="#" class="bad">Hello1</a><div id="ast">AST sCOOL</div>
        atributes:
                id: ['qwe']
        style:
___________________________________________________________________________________________________________________

Но, например, метод "getElementsByClassName" возвращает лист, как получить конкретный элемент.

Наберем:

	>>> document.getElementsByClassName(i)

Вывод:

	[div#i.i.asd
	    |____Hello2, 
	div.i
	    |____Hello3]

Как получить второй элемент этого листа? Аналогичным способом рабооты с листами. Не забываем, что нумерация в листах начинается с 0.

Введем:

	>>> document.getElementsByClassName(i)[1]

Вывод: 

	div.i
	    |____Hello3


Аналогичная работа с методами этого объекта и созданием новой переменной:

	>>> document.getElementsByClassName(i)[1].getInfo()

Вывод:
	
	< div.i >
        parent: < body >
        content: Hello3
        atributes:
                class: ['i']
        style:


Мы можем завести для него переменную:

	 >>> item = document.getElementsByClassName(i)[i]

Теперь наберем:

	>>> item

Вывод:

	div.i
	    |____Hello3

Аналогично:

	>>> item.getInfo()

Вывод:
	
	< div.i >
        parent: < body >
        content: Hello3
        atributes:
                class: ['i']
        style:

Попытка получения элемента по индексу, выходящему из длины листа, или попытка получения элемента по индексу не у листа, выдаст ошибку:

	  Index out of range: 3

___________________________________________________________________________________________________________________

При помощи этого парсера можно модифицировать HTML-документы. Возьмем для примера код из ПРИМЕРА 1.

	html.html:
		<!DOCTYPE html>
		<html lang="ru">
			<head>
				<link rel="stylesheet" href="style.css">
			</head>
			<body>
				<div id="qwe">
					<a href="#" class="bad">Hello1</a>
					<div id="ast">AST 
					sCOOL</div>
				</div>
				<div class="i asd" id="i" ast="asd" req>Hello2</div>
			<input>
				<div class="i">Hello3</div>
			</body>
		</html>

Далее наберем набор комманд:

	>>> div = document.createElement(div)

	>>> div.addAtribute(id=helloq, class=i)

	>>> document.getElementById(qwe).before(div)

Итак, мы создали элемент div, добавили ему атрибуты id и class, и добавили его перед элементом с id = qwe

Теперь выведем весь HTML, и посмотрим, что получилось:

	>>> document.text()

Результат:

	<!DOCTYPE html><html lang="ru">
	<head>
		<link rel="stylesheet" href="style.css">
	</head>
	<body>
		<div id="helloq" class="i"></div> <!-- ДОБАВИЛИ -->
		<div id="qwe"> <!-- ДОБАВИЛИ -->
			<a href="#" class="bad">Hello1</a>
			<div id="ast">AST sCOOL</div>
		</div>
		<div class="i asd" id="i" ast="asd" req="">Hello2</div>
		<input>
		<div class="i">Hello3</div>
	</body>
	</html>

Как видите, наш div добавился перед элементом qwe.