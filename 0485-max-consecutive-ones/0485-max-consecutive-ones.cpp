class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maks = 0;
        int cur = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                cur++;
                if(cur > maks){
                maks = cur;
                }
            }else{
                if(cur > maks){
                    maks = cur;
                }
                cur = 0;
            }
        }
        return maks;
    }
};