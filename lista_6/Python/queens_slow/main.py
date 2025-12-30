from math import factorial


def main():
    def reverse(nums, start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1

    def nextPermutation(nums, n):
        i = n - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            j = n - 1
            while j >= 0 and nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]

        reverse(nums, i + 1, n - 1)

    def checkNextPerm(nums, n) -> bool:
        for i in range(n):
            for j in range(i + 1, n, 1):
                colDiff = j - i
                rowDiff = abs(nums[i] - nums[j])
                if rowDiff == colDiff:
                    return False

        return True

    print("Enter number of columns (N): ", end="")
    n = int(input())
    currentPerm = []
    for i in range(n):
        currentPerm.append(i + 1)
    totalPermutations = factorial(n)
    solutionCount = 0
    print("")

    for k in range(totalPermutations):
        if checkNextPerm(currentPerm, n):
            solutionCount += 1
            print(f"Solution {solutionCount}: ", end="")
            for j in range(n):
                print(f"{currentPerm[j]} ", end="")
            print("")
        nextPermutation(currentPerm, n)
    print("")
    if solutionCount == 0:
        print("No solutions found.")
    else:
        print(f"Total solutions found: {solutionCount}")


if __name__ == "__main__":
    main()
