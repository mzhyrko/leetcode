class Solution {
public:
    
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long cnt = 0;
        long long sum = 0;
        while (j < n) {
            sum += nums[j];
    
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
};