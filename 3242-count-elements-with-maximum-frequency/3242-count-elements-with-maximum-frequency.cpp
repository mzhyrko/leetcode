class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        int max_freq = 0;
        int total_freq = 0;

        for (auto const& [num, freq] : freq_map) {
            if (freq > max_freq) {
                max_freq = freq;
                total_freq = freq;
            } else if (freq == max_freq) {
                total_freq += freq;
            }
        }
        return total_freq;
    }
};