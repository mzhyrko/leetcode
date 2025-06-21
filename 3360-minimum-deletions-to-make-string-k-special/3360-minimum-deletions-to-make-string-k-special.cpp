class Solution {
public:
    int getMin(int x, unordered_map<int,int> &freq, int &k){
        int removals = 0;
        for (auto &[a, val] : freq) {
            if (val < x) {
                removals += val; 
            } else {
                removals += max(0, val - x - k); 
            }
        }
        return removals;
    }

    int minimumDeletions(string word, int k) {
        unordered_map<int, int> freq;
        int ans = INT_MAX;

        for (char ch : word) {
            freq[ch]++;
        }

        for (auto &[a, val] : freq) {
            ans = min(ans, getMin(val, freq, k));
        }

        return ans;
    }
};