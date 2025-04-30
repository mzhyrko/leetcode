class Solution {
public:
    bool evenNoOfDigits(int n) {
        int cnt = 0;
        for (; n; n /= 10, cnt++);
        return cnt % 2 == 0;
    }

    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (auto& n : nums)
            if (evenNoOfDigits(n))
                result++;
        return result;
    }
};