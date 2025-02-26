class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int minSum=0;
        int maxSum=0;
        int absSum=arr[0];
        
        for(int i=0;i<arr.size();i++){
            maxSum=max(maxSum+arr[i],arr[i]);
            minSum=min(minSum+arr[i],arr[i]);
            
            absSum=max(absSum,max(abs(minSum),abs(maxSum)));
        }
        return absSum;
    }
};