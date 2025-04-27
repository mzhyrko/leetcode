class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }
        int counter = 0;
        for(int i = 0; i<nums.size() - 2; i++){
            if(float(nums[i] + nums[i+2]) == float(nums[i+1])/2){
                counter++;
            }
        }
        return counter;
    }
};