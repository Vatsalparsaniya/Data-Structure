import random

def main():
	
	# total amount in the beginning
	n = 15
	f = n

	print("______________________________\n")
	print("      BETTING GAME\n")
	print("______________________________\n")
	print("  *****    *****    *****\n")
	print("  *   *    *   *    *   *\n")
	print("  * B *    * E *    * T *\n")
	print("  *   *    *   *    *   *\n")
	print("  *****    *****    *****\n")
	print("______________________________\n")
	print("rules : \n")
	print("1) You have to chose between 1 to 3 \n")
	print("2) You are allowed to play till you have $0 \n")
	print("3) if you win then you will get 3*(BET AMOUNT)\n\n\n")
	print(f"how much amount you have ${n}")

	print("\n\n*******************************************\n")
	print("                GAME START    \n")
	print("*******************************************\n\n")

	while n != 0:
		bet_amount = int(input('Enter bet amount: '))
		random_num = random.randint(1, 3)

		user_num = int(input('Choose a number between 1 & 3: '))

		if n > 0:
			if random_num == user_num:
				n = n + 3 * bet_amount
				print ("Congratulations, you're right!\n")
				print (f'Now you have ${n}')
			else:
				n = n - bet_amount
				print ("Sorry, you're wrong!\n")
				print (f'Now you have ${n}')
		else:
			print ('You are not eligible to play game, you have NO MONEY.\n')

	print (f'You came with ${f}\n')
	print (f'Now you have ${n}\n')
	print ('Thank you for playing\n')

if __name__ == '__main__':
	main()