import random

def get_key(q, n):
	x = random.randint(1, 1000)
	y = random.randint(1, 1000)
	public_key_1 = q ** x % n
	public_key_2 = q ** y % n

	private_key_1 = public_key_2 ** x % n
	private_key_2 = public_key_1 ** y % n

	if private_key_2 == private_key_1:
		return private_key_1
	else:
		return 0

def encrypt(text, key):
	result = ""
	for char in text:
		result += chr(ord(char) + key)


	return result

def decode(text, key):
	result = ""
	for char in text:
		result += chr(ord(char) - key)


	return result

if __name__ == "__main__":
	stra = input()
	q = random.randint(1, 1000)
	n = random.randint(1, 1000)
	key = get_key(q, n)

	print("Encode (shift - ", key, "): ", encrypt(stra, key))
	print("Decode (shift - ", key, "): ", decode(encrypt(stra, key), key))
