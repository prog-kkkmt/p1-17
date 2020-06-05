import random
def key(q, n):
	x = random.randint(1, 50)
	y = random.randint(1, 50)
	A = q ** x % n
	B = q ** y % n
	key1 = B ** x % n
	key2 = A ** x % n
	return key1
def encrypt(text,key):
    result = ""
    for char in text:
        result += chr(ord(char) + key)
    return result
print("Введите текст")
text = input()
q = random.randint(1, 50)
n = random.randint(1, 50)
key = key(q, n)
print("Shift pattern : " + str(key))
print("Cipher: " + encrypt(text,key))
