class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        long long cntZeroesInFirstArray = 0;
        long long cntZeroesInSecondArray = 0;
        long long sum1 = 0;
        long long sum2=0;
        long long n1 = nums1.size();
        long long n2 = nums2.size();
        for(auto it:nums1){
            if(it==0) cntZeroesInFirstArray++;
            sum1+=it;
        }
        for(auto it:nums2){
            if(it==0) cntZeroesInSecondArray++;
            sum2+=it;
        }
        sum1 = sum1 + (cntZeroesInFirstArray);
        sum2 = sum2 + (cntZeroesInSecondArray);
        if(sum1<sum2 && !cntZeroesInFirstArray) return -1;
        if(sum1>sum2 && !cntZeroesInSecondArray) return -1;
        return max(sum1,sum2);

    }
};