# Implement a program that censors messages that contain words that appear on a list of supplied "banned words."
# for instance: What the heck
#				What the ****


# Author : Gautam Meena
# 2 April 2019
#  Week : 6, Problem : 2

import sys

# Words in banned.txt file
banned_words = set()

# Loading the text file of banned words
def load():
	banned = sys.argv[1]
	file = open(banned,"r")
	for line in file:
		banned_words.add(line.rstrip("\n"))
	file.close()
	return True


# Checking the words
def check(word):
	if word not in banned_words:
		print(word,end=" ")
	else:
		l = len(word);
		for i in range(l):
			print("*",end="")
		print(" ",end="")
	return

# main function
def main():
	# If user inputs wrong number of arguments
    if (len(sys.argv) != 2):
    	print("Usage: python bleep.py dictionary")
    	return 1
    load()

    # Getting input
    message = input("What message would you like to censor? \n")
    # Splitting the statement and storing it into a list
    message = message.split()
    
    # Checking if word 
    for m in message:
    	check(m)

    return

if __name__ == "__main__":
    main()
