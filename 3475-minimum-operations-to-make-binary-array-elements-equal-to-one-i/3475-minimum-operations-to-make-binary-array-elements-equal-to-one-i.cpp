class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n < 3)
            return -1;

        int i = 0;
        int cnt = 0;

        while (i < n - 2) {
            if (nums[i] == 0) {
                cnt++;
                for (int j = i; j < n && j < i + 3; j++)
                    nums[j] = nums[j] == 0 ? 1 : 0;
            }
            i++;
        }
        for (int j = n - 2; j < n; j++)
            if (nums[j] == 0)
                return -1;

        return cnt;
    }
};