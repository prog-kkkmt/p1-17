##	HTML PARSER V.2.3.1.610 (Count Lines, Fixed bugs, Correct output of warnings)
##	
##	DEVELOPER: OVOSKOP
##
##	COPYRIGHT. ALL RIGHT RESERVED.
##
##	CLASSES:
##		
##		TAG - Object of Tag
##		Node - Document Object Model or Node of Tags          
##
##


import sys
import os.path
import re
import inspect
import ctypes

from parserHTML import *

kernel32 = ctypes.windll.kernel32
kernel32.SetConsoleMode(kernel32.GetStdHandle(-11), 7)

def getDocument():
	filename = input("\nName of HTML file ('q' - exit): ")

	if filename == 'q':
		sys.exit()

	while not os.path.isfile(filename) or not 'html' in filename.split('.') or len(filename.split('.')) < 2:
		if filename == 'q':
			sys.exit()
		if not 'html' in filename.split('.') or len(filename.split('.')) < 2:
			filename = input("\n\033[41m{}\033[40m\n".format("File '" + filename +"' is not HTML file.") + "\nPlease enter correct name of HTML file ('q' - exit): ")
		else:
			filename = input("\n\033[41m{}\033[40m\n".format("File '" + filename +"' is not exist.") + "\nPlease enter correct name of HTML file ('q' - exit): ")

	document = parserHTML(filename) #парсируем файл

	if document:
		(document, (len_err, err)) = document
		print("\n\033[42m{}\033[40m\n".format("Parsed completed!"))
		if len_err:
			print("\033[30m\033[43m{}\033[37m\033[40m\n".format(
				f"{len_err} warning in {','.join(' < ' + e + ' > on line ' + str(l) for (e, l) in err)}")
			)
		return document
	else:
		return None

if __name__ == "__main__":

	print("HTML Parser v.2.3.1.610 (released 13.05.2020). Created by OVOSKOP.")
	print('Type "help" for more information.')
	
	document = getDocument()
	while not document:
		document = getDocument()
	print('\n')
	print(document)