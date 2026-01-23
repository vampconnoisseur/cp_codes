t = int(input()) 

for _ in range(t):
    n, k = map(int, input().split())
    s = input().strip()

    ans = 0
    i = -1  
    j = 0

    while j < n:
        if s[j] == '1':
            if i == -1 or j - i >= k - 1:
                ans += 1
            i = j + 1
        j += 1

    print(ans)