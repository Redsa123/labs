def main():
	def euklides(a, b):
		if(a == 0):
			return b
		elif(b == 0):
			return a

		while b != 0:
			
			temp = b
			b = a%b
			a = temp
		return a

	print("Enter value a: ")
	a = int(input())
	print("Enter value b: ")
	b = int(input())
	print(euklides(a, b))

if __name__ == "__main__":
	main()