class Solution {
public:
    int racecar(int n) {
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = 0x7fffffff;
            int k = 32 - __builtin_clz(i);
            if (i == (1 << k) - 1) dp[i] = k;
            dp[i] = min(dp[i], dp[(1 << k) - i - 1] + k + 1);
            for (int j = 0; j < k - 1; ++j) dp[i] = min(dp[i], dp[i - (1 << (k - 1)) + (1 << j)] + k + j + 1);
        }
        return dp[n];
    }
};
