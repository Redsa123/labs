from primes_lib import prime_numbers, prime, is_prime
import sys


def main():

	if len(sys.argv) != 3:
		print("Wrong number of arguments.\nUsage: python program <function> <number>")
	
	func_name = sys.argv[1]
	number = int(sys.argv[2])

	if (func_name == "pn"):
		print(f"Number of prime numbers less or equal to {number}: {prime_numbers(number)}")
	
	if (func_name == "pr"):
		print(f"{number}-th prime number: {prime(number)}")
	
	if (func_name == "ip"):
		print(f"Is {number} a prime number: {is_prime(number)}")


if __name__ == "__main__":
	main()