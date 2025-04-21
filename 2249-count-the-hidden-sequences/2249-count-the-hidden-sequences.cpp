class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long currentMin = lower;
        long long currentMax = upper;
        long long prefixSum = 0;

        for (int diff : differences) {
            prefixSum += diff;

            long long newLower = lower - prefixSum;
            long long newUpper = upper - prefixSum;

            currentMin = max(currentMin, newLower);
            currentMax = min(currentMax, newUpper);
        }

        if (currentMax >= currentMin) {
            return (currentMax - currentMin + 1);
        } else {
            return 0;
        }
    }
};