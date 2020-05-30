from cryptography.fernet import Fernet
key = Fernet.generate_key()
cipher_suite = Fernet(key)
cipher_text = cipher_suite.encrypt("This example is used to demonstrate cryptography module")
plain_text = cipher_suite.decrypt(cipher_text)
