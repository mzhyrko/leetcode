class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2));
        dp[n][1]=0;
        dp[n][0]=INT_MIN;
        for(int i=n-1;i>=0;i--){
            for(int x=0;x<2;x++){
                long long yes=dp[i+1][x^1]+(nums[i]^k);
                long long no=dp[i+1][x]+nums[i];
                dp[i][x]=max(yes,no);
            }
        }
        return dp[0][1];
    }
};