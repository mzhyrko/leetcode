class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = (nums.size()*(nums.size()-1))/2;
        unordered_map<int, int> mp;

        for(int i = 0; i<nums.size(); i++){
            if(mp[i - nums[i]]){
                res -= mp[i-nums[i]];
            }

            mp[i - nums[i]]++;;
        }
        return res;
    }
};