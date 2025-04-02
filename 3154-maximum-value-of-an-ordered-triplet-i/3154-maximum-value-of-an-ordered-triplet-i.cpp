class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maks = 0;
        for(int i = 0; i<nums.size()-2; i++){
            for(int j = i+1; j<nums.size()-1; j++){
                for(int k = j+1; k<nums.size(); k++){
                    long long smt = ((long long)nums[i] - (long long)nums[j]) * (long long)nums[k];
                    if(smt > maks)
                        maks = smt;
                }
            }
        }
        return maks;
    }
};