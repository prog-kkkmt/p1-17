message = 'GIEWIVrGMTLIVrHIQS' 
letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

for key in range (len (letters)):
	translate = ''
	for symbol in message:
		num = letters.find(symbol)
		num = num - key
		if num < 0: 
			num = num + len(letters)
		translate = translate + letters[num]
	else:
		translate = translate + symbol
	print ("Hacking key #%s: %s" % (key,translate))
