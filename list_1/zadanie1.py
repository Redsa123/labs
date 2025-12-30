def main():
	def euklides(a, b):
		if(a == 0):
			return b
		elif(b == 0):
			return a

		while b != 0:
			
			modulo = b
			b = a%b
			a = modulo
		return a

	print(euklides(12, 12))

if __name__ == "__main__":
	main()