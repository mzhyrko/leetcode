#define ll long long
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        int mod=1e9+7;
        int i=0,j=n-1;
        int ans=0;
        sort(nums.begin(),nums.end());
        auto subsequenceCount=[&](ll a,ll n){
            ll res=1;
            while(n){
                if(n & 1){
                    res=(res*a)%mod;
                    n--;
                }
                else{
                    a=(a*a)%mod;
                    n/=2;
                }
            }
            return res;
        };
        while(j>=i){
            if(nums[i]+nums[j]<=target){
                int numCount=j-i;
                int count=subsequenceCount(2,numCount);
                ans=(ans+count)%mod;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};