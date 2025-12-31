import master_mind

def printGuess(guess):
    print("[ ", end="")
    for i in range(master_mind.GUESSNUMBERS):
        print(f"{guess[i]} ", end="")
    print("] ", end="")

def main():
    allPosibilitiesList = master_mind.allPosibilities()

    validMask = [True] * master_mind.TOTALPERMUTATIONS

    attempts = 1

    print(f"Think of a sequence of {master_mind.GUESSNUMBERS} numbers (1-{master_mind.GUESSRANGE}).")
    print("I will try to guess it.")
    print("-" * 66)

    while True:
        guessIndex = -1
        for i in range(master_mind.TOTALPERMUTATIONS):
            if validMask[i]:
                guessIndex = i
                break

        if guessIndex == -1:
            print("Error: No valid possibilities left. You might have entered incorrect feedback previously.")
            break

        currentGuess = allPosibilitiesList[guessIndex]

        print(f"Attempt {attempts}: I guess ", end="")
        printGuess(currentGuess)
        print()

        print("On right place: ", end="")
        rightPlace = int(input())
        print("On wrong place: ", end="")
        wrongPlace = int(input())

        if rightPlace == master_mind.GUESSNUMBERS:
            print(f"I guessed it in {attempts} attempts!")
            break

        master_mind.filterList(allPosibilitiesList, validMask, currentGuess, rightPlace, wrongPlace)

        remaining = 0
        for i in range(master_mind.TOTALPERMUTATIONS):
            if validMask[i]:
                remaining += 1
        print(f"Possible codes remaining: {remaining}\n")

        attempts += 1

if __name__ == "__main__":
    main()