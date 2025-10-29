from math import sqrt

def isPrime(n):
	if n <= 1:
		return False
	if n == 2:
		return True
	if n%2 == 0:
		return False
	
	root = sqrt(n)
	i = 3

	while i <= root:
		if n%i == 0:
			return False
		i+=2

	return True


def main():
	print("Enter number: ", end="")
	n = int(input())
	print(f"{isPrime(n)}")

if __name__ == "__main__":
	main()