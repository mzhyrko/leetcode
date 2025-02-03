class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0 || k > nums.size()) {
            return {};
        }

        unordered_map<int, int> freqMap;
        vector<int> result;
        int distinctCount = 0;

        for (int i = 0; i < k; ++i) {
            if (freqMap[nums[i]] == 0) {
                distinctCount++;
            }
            freqMap[nums[i]]++;
        }
        result.push_back(distinctCount);

        for (int i = k; i < nums.size(); ++i) {

            if (freqMap[nums[i - k]] == 1) {
                distinctCount--;
            }
            freqMap[nums[i - k]]--;

            if (freqMap[nums[i]] == 0) {
                distinctCount++;
            }
            freqMap[nums[i]]++;

            result.push_back(distinctCount);
        }

        return result;
    }
};