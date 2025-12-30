import sys

def nth_prime(n):
    if n <= 0:
        print("Wrong arguments, n has to be greater than 0")
        return -1
    if n == 1:
        return 2

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

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Wrong number of arguments.")
    else:
        n = int(sys.argv[1])
        print(nth_prime(n))