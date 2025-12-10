import math

def dividers(n, dividers_list):
    index = 0
    if n % 2 == 0:
        while n % 2 == 0:
            n //= 2
            if not (n % 2 == 0):
                dividers_list.append(2)
                index = index + 1

    sqrroot = int(math.sqrt(n))
    i = 3
    while i <= sqrroot:
        if n % i == 0:
            while n % i == 0:
                n //= i
                if not (n % i == 0):
                    dividers_list.append(i)
                    index = index + 1
        i += 2

    if n > 1:
        dividers_list.append(n)

def totient(n):
    dividers_list = []
    dividers(n, dividers_list)

    index = len(dividers_list)

    result = n
    for i in range(index):
        result = result - (result // dividers_list[i])

    return result