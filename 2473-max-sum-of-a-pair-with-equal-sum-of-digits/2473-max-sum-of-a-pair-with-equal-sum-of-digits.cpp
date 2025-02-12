class Solution {
public:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> sumToMaxNum;
        int maxSum = -1;

        for (int num : nums) {
            int digitSum = getDigitSum(num);

            if (sumToMaxNum.find(digitSum) != sumToMaxNum.end()) {
                maxSum = max(maxSum, sumToMaxNum[digitSum] + num);
                sumToMaxNum[digitSum] = max(sumToMaxNum[digitSum], num);
            } else {
                sumToMaxNum[digitSum] = num;
            }
        }

        return maxSum;
    }

};