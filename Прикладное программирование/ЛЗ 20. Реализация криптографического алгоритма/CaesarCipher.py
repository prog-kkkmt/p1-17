def encrypt(text):
	result = ""
	for char in text:
		result += chr(ord(char) + 7)


	return result

def decode(text):
	result = ""
	for char in text:
		result += chr(ord(char) - 7)


	return result

if __name__ == "__main__":
	stra = input()

	print("Encode (shift - 7): ", encrypt(stra))
	print("Decode (shift - 7): ", decode(encrypt(stra)))