def mult(r, q, b):
    while (r <= q):
        r *= b
    return r

n = int(input())

for i in range(n):
    p, q, b = [int(x) for x in input().split()]

    s = {}

    while(True):
        r = p % q
        if (r % b == 0):
            print("Finite")
            break
        p = mult(r, q, b)
        if (s.get(p) != None):
            print("Infinite")
            break
        s[p] = True
