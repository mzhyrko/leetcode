class Solution {
    static const int mod = 1e9 + 7;

public:
    int possibleStringCount(string word, int max_length) {
        if (word.empty()) return 0;

        vector<int> group_sizes;
        int current_count = 1;

        for (size_t index = 1; index < word.size(); ++index) {
            if (word[index] == word[index - 1]) {
                current_count++;
            } else {
                group_sizes.push_back(current_count);
                current_count = 1;
            }
        }
        group_sizes.push_back(current_count);

        long long total_count = 1;
        for (int size : group_sizes)
            total_count = (total_count * size) % mod;

        if (max_length <= static_cast<int>(group_sizes.size())) return total_count;

        vector<int> dp(max_length, 0);
        dp[0] = 1;

        for (int size : group_sizes) {
            vector<int> new_dp(max_length, 0);
            long long prefix_sum = 0;
            for (int pos = 0; pos < max_length; ++pos) {
                if (pos > 0) prefix_sum = (prefix_sum + dp[pos - 1]) % mod;
                if (pos > size) prefix_sum = (prefix_sum - dp[pos - size - 1] + mod) % mod;
                new_dp[pos] = prefix_sum;
            }
            dp = new_dp;
        }

        long long invalid_count = 0;
        for (int pos = group_sizes.size(); pos < max_length; ++pos)
            invalid_count = (invalid_count + dp[pos]) % mod;

        return (total_count - invalid_count + mod) % mod;
    }
};