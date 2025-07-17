class Solution {
public:
    int maximumLength(vector<int>& v, int k) {
        int n = v.size(); 
        vector<vector<int>> dp(n, vector<int>(k, 0));
        int mx{}; 
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i ; ++j){
                int mod = (v[i] + v[j]) % k; 
                int &cur = dp[i][mod]; 
                cur = max(cur, dp[j][mod] + 1); 
                mx = max(mx, cur); 
            }
        }
        return mx + 1; 
    }
};