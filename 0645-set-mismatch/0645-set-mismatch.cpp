class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);

        for (int x : nums) {
            cnt[x]++;
        }

        int duplicate = -1;
        int missing = -1;

        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) missing = i;
            if (cnt[i] == 2) duplicate = i;
        }

        return {duplicate, missing};
    }
};
