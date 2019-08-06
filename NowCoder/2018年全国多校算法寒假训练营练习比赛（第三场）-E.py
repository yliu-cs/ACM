import math
while True:
    try:
        a = int(input())
        b = math.factorial(a)
        print(b)
    except EOFError:
        break
