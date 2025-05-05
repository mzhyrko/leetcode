class Solution {
public:
    int dp[1000];
    const int mod = 1e9 + 7;

    Solution() {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
    }

    int numTilings(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else if (n == 3)
            return dp[n] = 5;

        dp[n - 1] = numTilings(n - 1);
        int val = ((2LL * dp[n - 1]) % mod + dp[n - 3]) % mod;
        return dp[n] = val;
    }
};
