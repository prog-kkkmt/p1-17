message = "This is program to explain reverse cipher."
translete = ""
i = len(message) - 1

while i >= 0:
	translete = translete + message[i]
	i = i - 1
print ("This cipher text is : ", translete)

	