MD = 163577857

def compFIJ(fArr, n, j):
    s = n - j + 1
    for h in range (2, j + 1):
        s += fArr[j - h + 1] * (n - j + 1)
    return s

def compAns(fArr, n):
    s = 0
    for i in range (n):
        s += fArr[i + 1] * ((n - i) * (n - i - 1) // 2 + 1)
    return s

t = int(input())

for h in range (t):
    n, k = list(map(int, input().split()))

    if (k == 1):
        print(n * (n + 1) // 2 % MD)
        continue

    dp = [[0 for i in range (n + 1)] for j in range (k)]

    for i in range (1, n + 1):
        dp[1][i] = n - i + 1

    for i in range (2, k):
        for j in range (1, n + 1):
            dp[i][j] = compFIJ(dp[i - 1], n, j)

    print(compAns(dp[k - 1], n) % MD)
