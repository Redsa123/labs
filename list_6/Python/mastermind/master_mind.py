GUESSRANGE = 6
GUESSNUMBERS = 4
TOTALPERMUTATIONS = GUESSRANGE ** GUESSNUMBERS

def generateRecursive(index, currentSequence, fullList, listCount):
    if index == GUESSNUMBERS:
        fullList.append(list(currentSequence))
        listCount[0] += 1
        return

    for i in range(1, GUESSRANGE + 1):
        currentSequence[index] = i
        generateRecursive(index + 1, currentSequence, fullList, listCount)

def allPosibilities():
    result = []
    currentSequence = [0] * GUESSNUMBERS
    listCount = [0]

    generateRecursive(0, currentSequence, result, listCount)

    return result

def calculateMatches(secret, guess, resultOut):
    rightPlace = 0
    wrongPlace = 0

    secretFreq = [0] * (GUESSRANGE + 1)
    guessFreq = [0] * (GUESSRANGE + 1)

    for i in range(GUESSNUMBERS):
        if secret[i] == guess[i]:
            rightPlace += 1
        else:
            secretFreq[secret[i]] += 1
            guessFreq[guess[i]] += 1

    for i in range(1, GUESSRANGE + 1):
        wrongPlace += min(secretFreq[i], guessFreq[i])

    resultOut[0] = rightPlace
    resultOut[1] = wrongPlace

def filterList(allPermutations, validMask, currentGuess, userRightPlace, userWrongPlace):
    tempResult = [0, 0]

    for i in range(TOTALPERMUTATIONS):
        if not validMask[i]:
            continue

        candidate = allPermutations[i]

        calculateMatches(candidate, currentGuess, tempResult)

        if tempResult[0] != userRightPlace or tempResult[1] != userWrongPlace:
            validMask[i] = False