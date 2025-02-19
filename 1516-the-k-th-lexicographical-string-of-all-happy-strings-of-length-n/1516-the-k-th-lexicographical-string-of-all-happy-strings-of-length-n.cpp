class Solution {
private:
    int count = 0;
    string result = "";

    void generateString(int n, string current, int k) {
        if (count == k) return;
        if (current.length() == n) {
            count++;
            if (count == k) result = current;
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (!current.empty() && current.back() == ch) continue;
            generateString(n, current + ch, k);
        }
    }

public:
    string getHappyString(int n, int k) {
        generateString(n, "", k);
        return count < k ? "" : result;
    }
};