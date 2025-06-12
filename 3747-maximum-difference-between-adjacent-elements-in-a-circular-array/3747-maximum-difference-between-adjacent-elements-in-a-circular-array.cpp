class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maks = abs(nums[0] - nums[nums.size()-1]);

        for(int i = 0; i<nums.size()-1; i++){
            if(abs(nums[i]-nums[i+1]) > maks){
                maks = abs(nums[i]-nums[i+1]);
            }
        }
        return maks;
    }
};