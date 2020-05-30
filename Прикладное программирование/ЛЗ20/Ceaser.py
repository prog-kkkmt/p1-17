def cypher(str, key):
    res = ""
    for i in range(len(str)):
        if (str[i].islower()):
            res += chr((ord(str[i]) + key - 97) % 26 + 97)
        else:
            res += chr((ord(str[i]) + key - 65) % 26 + 65)
    return res

str = input()
key = int(input())
print(cypher(str, key))
