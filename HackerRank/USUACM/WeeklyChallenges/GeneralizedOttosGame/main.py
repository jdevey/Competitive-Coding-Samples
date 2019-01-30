t = int(input())
for i in range (0, t):
    n = int(input()); a, b = map(lambda x : int(x), input().split())
    if (a > b): a, b = b, a
    print("First" if ((n % (a + b) >= b) or ((n % (a + b) // a) & 1)) else "Second")
