import sys
import math

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

    return s

def count_primes(sieve_array, n):
    count = 1

    for i in range(3, n+1, 2):
        if sieve_array[i]:
            count += 1

    return count

def main():
    if len(sys.argv) != 2:
        print("Wrong number of arguments")
        return -1

    n = int(sys.argv[1])

    if n <=1:
        print("N has to be greater than 1")
        return -1

    s = compute_sieve(n)

    count = count_primes(s, n)

    print(count)

if __name__ == "__main__":
    main()