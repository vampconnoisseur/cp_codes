from collections import defaultdict

def prime_factors(x):
    factors = set()
    while x % 2 == 0:
        factors.add(2)
        x //= 2
    i = 3
    while i * i <= x:
        while x % i == 0:
            factors.add(i)
            x //= i
        i += 2
    if x > 1:
        factors.add(x)
    return factors


t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    freq = defaultdict(int)
    repeated = False

    for num in a:
        primes = prime_factors(num)
        for p in primes:
            freq[p] += 1
            if freq[p] > 1:
                repeated = True
                break
        if repeated:
            break

    if repeated:
        print(0)
        continue

    found_adjacent = False
    for num in a:
        primes_plus = prime_factors(num + 1)
        for p in primes_plus:
            if p in freq:
                found_adjacent = True
                break
        if found_adjacent:
            break

    if found_adjacent:
        print(1)
    else:
        print(2)