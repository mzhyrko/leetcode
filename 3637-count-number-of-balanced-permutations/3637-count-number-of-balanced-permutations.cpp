class Solution {
    long long power(long long a, long long b, long long& mod) {
        if (b == 0)
            return 1LL;
        long long temp = power(a, b / 2, mod);
        long long res = (temp * temp) % mod;
        if (b % 2 != 0)
            res = (res * a) % mod;
        return res;
    }
    long long f(int i, int j, int s, int t, long long& sum, vector<int>& freq,
                vector<vector<vector<long long>>>& dp, long long& fact,
                long long& mod, vector<long long>& inv) {
        if (i == 10) {
            if (j != t || 2 * s != sum)
                return 0;
            return fact;
        }

        if (dp[i][j][s] != -1)
            return dp[i][j][s];

        long long ans = 0;
        for (int k = 0;
             k <= freq[i] && (j + k) <= t && 2 * (s + (i * k)) <= sum; k++) {
            ans = (ans + (((inv[k] * inv[freq[i] - k]) % mod) *
                          f(i + 1, j + k, s + (i * k), t, sum, freq, dp, fact,
                            mod, inv))) %
                  mod;
        }
        return dp[i][j][s] = ans;
    }

public:
    int countBalancedPermutations(string& num) {
        int n = num.size();
        long long fact = 1, sum = 0, mod = 1e9 + 7;
        vector<int> freq(10, 0);
        for (int i = 0; i < n; i++) {
            freq[num[i] - '0']++;
            sum += (num[i] - '0');
        }

        vector<vector<vector<long long>>> dp(
            10, vector<vector<long long>>(n / 2 + 1,
                                          vector<long long>(sum + 1, -1)));

        for (int i = 1; i <= n / 2; i++)
            fact = (fact * i) % mod;
        for (int i = 1; i <= (n - (n / 2)); i++)
            fact = (fact * i) % mod;

        vector<long long> inv(n + 1, 1);
        for (int i = 2; i <= n; i++)
            inv[i] = (inv[i - 1] * power(i, mod - 2, mod)) % mod;
        return f(0, 0, 0, n / 2, sum, freq, dp, fact, mod, inv);
    }
};