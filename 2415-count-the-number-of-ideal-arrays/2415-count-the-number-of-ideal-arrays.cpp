class Solution {
public:
    int MOD = 1e9 + 7;
    long long factorial_mod(long long n) {
        long long result = 1;
        for (long long i = 1; i <= n; ++i) {
            result = (result * i) % MOD;
        }
        return result;
    }
    long long mod_inverse(long long x) {
        long long result = 1, power = MOD - 2;
        while (power > 0) {
            if (power % 2 == 1) {
                result = (result * x) % MOD;
            }
            x = (x * x) % MOD;
            power /= 2;
        }
        return result;
    }
    long long comb_mod(long long n, long long k) {
        if (k > n)
            return 0;
        long long num = factorial_mod(n);
        long long denom = (factorial_mod(k) * factorial_mod(n - k)) % MOD;
        return (num * mod_inverse(denom)) % MOD;
    }
    int idealArrays(int n, int maxValue) {
        map<int, int> list;
        for (int i = 1; i <= maxValue; i++) {
            list[i] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (auto [x, y] : list) {
                cnt += y;
                cnt %= MOD;
            }
            ans = (ans + (comb_mod(n - 1, i - 1) * cnt) % MOD) % MOD;
            map<int, int> temp;
            for (auto [x, y] : list) {
                if (x * 2 > maxValue) {
                    break;
                }
                int t = x * 2;
                while (t <= maxValue) {
                    temp[t] += y;
                    t = t + x;
                }
            }
            if (temp.size() == 0) {
                break;
            }
            list = temp;
        }
        return ans;
    }
};