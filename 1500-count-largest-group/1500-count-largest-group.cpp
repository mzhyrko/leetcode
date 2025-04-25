class Solution {
public:
    int sumOfDigits(int number) {
        int total = 0;
        while (number > 0) {
            total += number % 10;
            number /= 10;
        }
        return total;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> groupCount;

        for (int i = 1; i <= n; i++) {
            int sum = sumOfDigits(i);
            groupCount[sum]++;
        }

        int maxSize = 0;
        int count = 0;

        for (auto& p : groupCount) {
            if (p.second > maxSize) {
                maxSize = p.second;
                count = 1;
            } else if (p.second == maxSize) {
                count++;
            }
        }

        return count;
    }
};
