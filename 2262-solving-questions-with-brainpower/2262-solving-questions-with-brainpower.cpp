class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); 

        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int skip = questions[i][1];

            long long take = points + (i + skip + 1 < n ? dp[i + skip + 1] : 0);
            long long notTake = dp[i + 1];

            dp[i] = max(take, notTake);
        }

        return dp[0];
    }
};