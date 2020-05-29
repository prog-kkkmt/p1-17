rot13trans = str.maketrans ('ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz', 
   'NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm')

def rot13 (text):
	return text.translate (rot13trans)
def main ():
	txt = 'ROT13 Algorithm'
	print (rot13(txt))

if __name__ == "__main__":
	main()
