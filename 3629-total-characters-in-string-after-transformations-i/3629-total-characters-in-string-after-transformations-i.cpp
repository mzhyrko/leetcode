class Solution {
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> vec(26, 0);
        for (auto c : s) {
            vec[c - 'a']++;
        }
        int ind = 25;
        for (int i = 0; i < t; i++) {
            int next = (ind + 1) % 26;
            vec[next] = (vec[ind] + vec[next]) % mod;
            ind = (ind + 25) % 26; 
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + vec[i]) % mod;
        }
        return ans;
    }
};