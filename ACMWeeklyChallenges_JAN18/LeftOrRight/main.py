t = int(input())
a = [(1, 0), (0, 1)]
for i in range (2, 100001): a.append(((a[i - 1][1] + a[i - 2][1]) % 1000000007, (a[i - 1][0] + a[i - 2][0]) % 1000000007))
for i in range (0, t): n = int(input()); print(a[n][0], a[n][1])
