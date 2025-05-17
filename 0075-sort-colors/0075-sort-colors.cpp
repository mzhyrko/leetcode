class Solution {
public:
    void sortColors(vector<int>& nums) {
        int min;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            min = i;
            for(int j = i+1; j<n; j++){
                if(nums[j] < nums[min]){
                    min = j;
                }
            }
            swap(nums[i], nums[min]);
        }
    }
};