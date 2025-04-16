class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        long long pair = 0;
        int n = nums.size();

        while (j < n) {
            pair += mp[nums[j]];
            ++mp[nums[j]];

            while (i <= j && pair >= k) {
                ans += (n - j);
                --mp[nums[i]];
                pair -= mp[nums[i]];
                ++i;
            }
            ++j;
        }
        return ans;
    }
};