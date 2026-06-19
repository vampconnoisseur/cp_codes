t = int(input()) 

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    pref = [0] * n
    pref[0] = a[0]
    for i in range(1, n):
        pref[i] = max(pref[i-1], a[i])

    ans = 0

    if n % 2 == 0:
        start = n - 1  
    else:
        start = n - 2  

    for i in range(start, 0, -2):
        val = pref[i] 
        if a[i-1] >= val:
            ans += (a[i-1] - (val - 1))
            a[i-1] = val - 1

        if i + 1 < n and a[i+1] >= val:
            ans += (a[i+1] - (val - 1))
            a[i+1] = val - 1

    print(ans)