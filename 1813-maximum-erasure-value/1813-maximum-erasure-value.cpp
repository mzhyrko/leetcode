class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int> s;
        int i = 0, j = 0, n = nums.size(), sum = 0, maxSum = 0;
        while (j < n) {
            while (s.count(nums[j])) {
                s.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            s.insert(nums[j]);
            sum += nums[j];
            maxSum = max(sum, maxSum);
            j++;
        }
        return maxSum;
    }
};