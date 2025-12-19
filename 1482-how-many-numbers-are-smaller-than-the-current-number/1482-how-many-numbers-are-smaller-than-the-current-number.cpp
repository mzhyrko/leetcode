class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        for (int k = 0; k < n; k++) {
            for (int q = 0; q < n; q++) {
                if (k != q && nums[k] > nums[q])
                    ans[k]++;
            }
        }

        return ans;
    }
};