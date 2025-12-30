import sys

def main():
    position = []
    raw = []
    diagonal1 = []
    diagonal2 = []
    solutions = 0
    n = int(sys.argv[1])

    for i in range (0, n):
        position.append(0)
        raw.append(False)
        diagonal1.append(False)
        diagonal1.append(False)
        diagonal2.append(False)
        diagonal2.append(False)

    def queens():
        set(0)
    def set(i):
        if i == n:
            printResult()
            return

        for j in range (0, n):
            diagonal1_idx = i + j
            diagonal2_idx = i - j + (n-1)

            if not (raw[j] or diagonal1[diagonal1_idx] or diagonal2[diagonal2_idx]):
                position[i]= j
                raw[j] = True
                diagonal1[diagonal1_idx] = True
                diagonal2[diagonal2_idx] = True

                set(i + 1)

                position[i] = 0
                raw[j] = False
                diagonal1[diagonal1_idx] = False
                diagonal2[diagonal2_idx] = False

    def printResult():
        nonlocal solutions
        solutions += 1

        for i in range (0, n):
            print(f"{position[i] + 1} ", end="")

        print(f"\n")

    queens()
    print(f"Total number of solutions: {solutions}")


if __name__ == "__main__":
    main()