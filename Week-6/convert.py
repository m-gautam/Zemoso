import sys
import math


result = ""
unit_place = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
two_digits = ["ten", "eleven", "tweleve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tenth_place = ["twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]
tenth_power = ["", "thousand", "million", "billion", "trillion"]



def convert(number):

	while number != 0:
		no = number%1000
		number = number/1000
		digits_processed = 0
		no_length = len(number)
		remaining = no_length - digits_processed 

		largest_power = no_length/3

		if (no_length > 3):
			return
		if(no_length == 3):
			three_digit(no)

		elif (no_length == 2):
			two_digit(no)	

		elif (no_length == 1):
			one_digit(no)
		
	

	return;



def one_digit(number):
	global result
	result = result + unit_place[ord(number) - ord('0')] + " "
	return 



def two_digit(number):
	global result

	if (int(number) <= 19):
		result = result + two_digits[int(number) - 10] + " "
	else:
		result = result + tenth_place[int(number[0])-2] + " "
		one_digit(number[1])
	
	return


def three_digit(number):
	global result
	one_digit(number[0])
	result  = result + "hundred " + "and" + " "
	two_digit(number[1:])
	return

def main():

	if (len(sys.argv) != 2):
		print("Usage: python convert.py number")
	number = sys.argv[1]
	convert(number)
	print(result)


if __name__ == '__main__':
	main()