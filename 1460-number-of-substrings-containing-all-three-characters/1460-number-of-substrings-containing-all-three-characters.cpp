class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> count(3, 0);
        int lo = 0;
        for(int hi = 0; hi < n; hi++) {
            count[s[hi] - 'a']++;
            while(min({count[0], count[1], count[2]}) > 0) {
                ans += (n - hi);
                count[s[lo++] - 'a']--;
            }
        }
        return ans;
    }
};