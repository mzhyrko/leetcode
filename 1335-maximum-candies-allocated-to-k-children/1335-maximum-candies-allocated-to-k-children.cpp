class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for (int num : candies) {
            sum += num;
        }
        if (sum < k) {
            return 0;
        }
        long long low = 1;
        long long high = sum / k;
        int res = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long total = 0;
            for (int num : candies) {
                total += num / mid;
            }
            if (total >= k) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};