class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maks = 0;
        int cur = nums[0];
        
        if(nums.size() == 1){
            return nums[0];
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                cur += nums[i];
                if (i == nums.size()-1) {
                    if (cur > maks) {
                        maks = cur;
                    }
                }
            }else if (nums[i] <= nums[i - 1]) {
                if (cur > maks) {
                    maks = cur;
                }
                cur = nums[i];
            }
        }
        return maks;
    }
};