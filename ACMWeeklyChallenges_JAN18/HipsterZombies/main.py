t = int(input())
def fib(n):
    if n == 1: return (1, 1)
    m = fib(n // 2)
    return ((m[0] + m[1])**2 - m[1]**2, m[0]** 2 + m[1]**2) if n & 1 else (m[0]**2 + m[1]**2, m[0]** 2 - (m[0] - m[1])**2)
for i in range (0, t): print(fib(int(input()))[0])
