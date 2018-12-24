import math

maxn = 1005

def PrimeInit():
    IsPrime = [True] * maxn
    Prime = []
    for i in range(2, maxn):
        if IsPrime[i]:
            Prime.append(i)
            for j in range(i * i, maxn, i):
                IsPrime[j] = False;
    return Prime

def main():
    Prime = PrimeInit()
    T = int(input())
    for Case in range(T):
        N = int(input())
        Book, Up, Down = 1, 1, 1
        for i in Prime:
            Book *= i
            if Book > N:
                break
            Up *= i
            Down *= i + 1
        Gcd = math.gcd(Up, Down)
        print(str(Up // Gcd) + '/' + str(Down // Gcd))

if __name__ == '__main__':
    main()

