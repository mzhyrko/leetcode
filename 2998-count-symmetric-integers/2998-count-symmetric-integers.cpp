class Solution {
public:
    int symmetric(int n) {
        int count = 0;
        while (n) {
            n /= 10;
            count++;
        }
        return count;
    }

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for (int i = low; i <= high; i++) {
            int count = symmetric(i);
            int half = count / 2;
            if (!(count & 1)) {
                int temp = i;
                int leftSum = 0, rightSum = 0;
                while (count != 0) {
                    if (count > half) {
                        int digit = temp % 10;
                        temp /= 10;
                        leftSum += digit;
                    } else {
                        int digit = temp % 10;
                        temp /= 10;
                        rightSum += digit;
                    }
                    count--;
                }
                if (leftSum == rightSum) {
                    ans++;
                }
            }
        }
        return ans;
    }
};