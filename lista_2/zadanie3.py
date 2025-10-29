from math import sqrt


def main():
	def dividers(n):
		if n%2 == 0:
			mult2 = 0;
			while n%2==0:
				mult2+=1
				n /= 2
			print(f"2^{mult2}", end="")
			if n > 1:
				print("*", end="")

		root = sqrt(n)
		i = 3
		while i <= root:
			if n%i==0:
				mult = 0
				while n%i==0:
					mult += 1
					n /= i
				print(f"{i}^{mult}", end="")
				if n > 1:
					print("*", end="")
			i+=2

		if n > 1:
			print(f"{n}^1")

	print("Enter number: ", end="")
	n = int(input())
	dividers(n)


if __name__ == "__main__":
	main()