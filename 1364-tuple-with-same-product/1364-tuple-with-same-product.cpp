class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> frequency;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                frequency[nums[i] * nums[j]]++;
            }
        }

        int sum = 0;

        for (const auto& pair : frequency) {
            sum += (pair.second * (pair.second - 1)) / 2;
        }
        return sum*8;
    }
};