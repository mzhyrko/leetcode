class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res;
        int counter = 0;

        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                res.push_back(nums[i]);
            }
            else{
                counter++;
            }
        }
        
        for(int i = 0; i<counter; i++){
            res.push_back(0);
        }

        return res;
    }
};