class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long n=nums.size();
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            long long s=i+1,e=n-1;
            long long left=-1,right=-1;
            while(s<=e){
                long long mid=(s+e)/2;
                if(nums[mid]>=lower-nums[i]){
                    left=mid;
                    e=mid-1;
                }
                else s=mid+1;
            }
            s=i+1,e=n-1;
            while(s<=e){
                long long mid=(s+e)/2;
                if(nums[mid]<=upper-nums[i]){
                    right=mid;
                    s=mid+1;
                }
                else e=mid-1;
            }
            if(left!=-1 && right!=-1 && left<=right)ans=ans+(right-left+1);
        }
        return ans;
    }
};