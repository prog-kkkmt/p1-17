def partial_key(pub_key1, private_key1, pub_key2):
    return (pub_key1 ** private_key1) % pub_key2

def full_key(part_key2, private_key1, pub_key2):
    return (part_key2 ** private_key1) % pub_key2

def cypher(full_key, message):
    res = ""
    for c in message:
        res += chr(ord(c)+ full_key)
        
    return res

my_pub_key = int(input())
my_priv_key = int(input())    
oppon_pub_key = int(input())
oppon_priv_key = int(input())
message = input()
part_key = partial_key(my_pub_key, my_priv_key, oppon_pub_key)
print ("My partial key: ", part_key)
part_key = partial_key(my_pub_key, oppon_priv_key, oppon_pub_key)
print ("Opponent's partial key: ", part_key)
key = full_key(part_key, my_priv_key, oppon_pub_key)
print ("Full key: ", key)
print("Cypher message: ", cypher(key, message))
