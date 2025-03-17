class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        bool pair = true;

        if (n % 2 == 0) {

            for (int i : nums) {
                mp[i]++;
            }

            for (auto& i : mp) {
                if (i.second % 2 == 1) {
                    pair = false;
                    break;
                }
            }
        }
        if (pair) {
            return true;
        }
        return false;
    }
};
