class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int, int> mp;
        set<int> st1, st2;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            st1.insert(nums[i]);
        }
        int k = st1.size();
        int i = 0, j = 0;
        int c = 0;
        while (j < nums.size()) {
            mp[nums[j]]++;
            if (mp.size() == k) {

                while (mp.size() >= k) {
                    c += n - j;
                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0) {
                        mp.erase(nums[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return c;
    }
};