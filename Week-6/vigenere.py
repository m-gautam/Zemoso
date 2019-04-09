# Implement a program that encrypts messages using Vigenère’s cipher, per the below.
# $ python vigenere.py ABC 
# plaintext:  HELLO
# ciphertext: HFNLP

# Author : Gautam Meena
# 2 April 2019
# Week : 2, Problem : 2


import sys

A = ord('A')
Z = ord('Z')
a = ord('a')
z = ord('z')
alphabets = 26

# Function for encrypting the message
def encrypt(plaintext, key):
	# length of key
	len_key = len(key)
	l = 0;
	print("ciphertext: ", end="")
	for word in plaintext:
		for w in word:
			if not w.isalpha():
				print(w,end="")
				continue
			if (l >= len_key):
				l = 0
			# Handling the uppercase letters
			if w.isupper():
				c = A + ((ord(w) - A) + (ord(key[l].upper()) - A))%alphabets
				w = chr(c)
				print(w,end="")
			# Handling the lower letters
			else:
				c = a + ((ord(w) - a) + (ord(key[l].upper()) - A))%alphabets
				w = chr(c)
				print(w,end="")
			l += 1
		print(" ",end="")
	print("\n")
	return


# main function
def main():
	# If user inputs wrong number of arguments
	if (len(sys.argv) != 2) or (not (sys.argv[1].isalpha())):
		print("Usage: python vigenere.py k")
		return 1
	# Getting input from user
	plaintext = input("plaintext: ")
	key = sys.argv[1]
	# Splitting the input and storing it into a list
	plaintext = plaintext.split()
	encrypt(plaintext, key)
	return


if __name__ == "__main__":
	main()