class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > k) {
                s.insert(nums[i]);
                nums[i] = k;
            }
        }
        
        for (auto u : nums) {
            if (u != k)
                return -1;
        }
        
        return s.size();
    }
};