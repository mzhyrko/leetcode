class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        int odd=0,even=1;
        int sum=0,count=0;

        for(int num:arr){
            sum+=num;
            if(sum%2==0){
                count=(count+odd)%mod;
                even++;
            }else{
                count=(count+even)%mod;
                odd++;
            }
        }
    return count;
    }
};