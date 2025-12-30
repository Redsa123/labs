import sys

def calc_newton(n, k):
    tab = [0] * (k + 1)
    tab[0] = 1

    # Pascal triangle
    for i in range(1, n + 1):
        j_max = i if i < k else k

        for j in range(j_max, 0, -1):
            tab[j] = tab[j] + tab[j - 1]

    result = tab[k]
    return result

def main():
    if len(sys.argv) != 3:
        print("Wrong number of arguments")
        return -1

    n = int(sys.argv[1])
    k = int(sys.argv[2])

    if k < 0 or n < 0:
        print("Arguments have to be greater than 0")
        return -1

    if k > n:
        print("Wrong arguments, k has to be greater than n.\nUsage: python main.py <n> <k>")
        return -1

    # Optimisation for (n,k) = (n, n-k) (formula)
    if k > n // 2:
        k = n - k

    if k == n:
        return -1

    print(f"Result: {calc_newton(n, k)}")

if __name__ == "__main__":
    main()