#Диффи-Хеллмана
import random

def key(q, n):
	x = random.randint(1, 100)
	y = random.randint(1, 100)

	A = q ** x % n
	B = q ** y % n

	key1 = B ** x % n
	key2 = A ** x % n

	return key1

def encrypt(text,key):
    result = ""
# transverse the plain text
    for char in text:

# Encrypt uppercase characters in plain text

        result += chr(ord(char) + key)
    return result
#check the above function
text = "CEASER CIPHER DEMO"
q = random.randint(1, 100)
n = random.randint(1, 100)
key = key(q, n)

print("Plain Text : " + text)
print("Shift pattern : " + str(key))
print("Cipher: " + encrypt(text,key))