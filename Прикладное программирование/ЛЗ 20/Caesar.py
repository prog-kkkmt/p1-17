#Шифр Цезаря
def encrypt(text,key):
    result = ""
# transverse the plain text
    for char in text:

# Encrypt uppercase characters in plain text

        result += chr(ord(char) + key)
    return result
#check the above function
text = "CEASER CIPHER DEMO"
key = 4

print("Plain Text : " + text)
print("Shift pattern : " + str(key))
print("Cipher: " + encrypt(text,key))