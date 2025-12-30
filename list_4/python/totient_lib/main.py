import sys
from totient import totient

def main():
    argc = len(sys.argv)
    argv = sys.argv

    if argc < 2:
        print("\nWrong number of arguments.\nUsage: /program <number>", end="")

    print("\n", end="")
    for i in range(1, argc):
        print(f"totient({argv[i]}) = {totient(int(argv[i]))};")

    print("\n", end="")

if __name__ == "__main__":
    main()