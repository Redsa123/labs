import math

# (pn) returns number of prime number less or equal to n

def compute_sieve(n):
	if n < 2:
		return 0

	s = [True] * (n + 1)

	s[0] = s[1] = False

	root = int(math.sqrt(n))

	for i in range(2, root + 1): #python iterates to n-1
		if s[i]:
			for j in range(i * i, n + 1, i):
				s[j] = False
			for j in range(i * i, n + 1, i):
				s[j] = False

	return s

def count_primes(sieve_array, n):
	count = 1

	for i in range(3, n+1, 2):
		if sieve_array[i]:
			count += 1
	return count



def prime_numbers(n) -> long:
	count = count_primes(compute_sieve(n), n)
	return count
	



# (pr) returns Nth prime number
def prime(n) -> long:

    if n <= 0:
        print("Wrong arguments, n has to be greater than 0")
        return None
    if n == 1:
        return None

    tab = [0] * n

    count = 1
    tab[0] = 2

    i = 3
    flag = 1

    while True:
        flag = 1

        for j in range(count):
            if i % tab[j] == 0:
                flag = 0

        if flag:
            tab[count] = i
            count += 1

        if count == n:
            return i

        i += 2

# (ip) checkes if number is prime
def is_prime(n) -> bool:
	if n <= 1:
		return False
	if n == 2:
		return True
	if n%2 == 0:
		return False
	
	root = int(math.sqrt(n))
	i = 3

	while i <= root:
		if n%i == 0:
			return False
		i+=2

	return True