#Алгоритм обратного шифрования
message = 'My first cipher.'
cipher = ''
i = len(message) - 1

while i >= 0:
   cipher = cipher + message[i]
   i = i - 1
print('The cipher text is : ', cipher)
