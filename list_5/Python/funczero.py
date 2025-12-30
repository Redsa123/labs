from math import cos,  sin

EPSILON = 0.1

def write(f, x) -> float:
    print(f"{f(x)}")

def test_func(x: float) -> float:
    return sin(x)

def find_zero(f, a: float, b: float, eps: float) -> float:
    mid = (a+b)/2

    if f(mid) == 0:
        return mid
    
    while (b-a) / 2 > eps:
        if f(a) * f(mid) < 0:
            b = mid
        else:
            a = mid
        mid = (a+b)/2
        
    return mid

def main():
    a = int(input("Enter a: "))
    b = int(input("Enter b: "))
    precision = int(input("Choose precision: "))

    for i in range(1, precision):
        result: float = find_zero(test_func, a, b, pow(EPSILON, i))
        print(f"result: {result}")

if __name__ == "__main__":
    main()