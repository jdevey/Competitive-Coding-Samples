class Solution {
public:
    long long cnt = 0;
    int maxN;
    void rec(bool* a, int n) {
        if (n == 0) {
            ++cnt;
            return;
        }
        for (int i = maxN; i > 0; --i) {
            if (!a[i] && (i % n == 0 || n % i == 0)) {
                a[i] = true;
                rec(a, n - 1);
                a[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        maxN = n;
        bool a[n + 1] = {};
        rec(a, n);
        return cnt;
    }
};
