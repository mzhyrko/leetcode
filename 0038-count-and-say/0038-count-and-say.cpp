class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = "1";
        for (int i = 2; i <= n; ++i) {
            prev = generateNext(prev);
        }
        return prev;
    }
    
private:
    string generateNext(const string& prev) {
        string res;
        int i = 0;
        while (i < prev.size()) {
            char current = prev[i];
            int count = 0;
            while (i < prev.size() && prev[i] == current) {
                ++count;
                ++i;
            }
            res += to_string(count) + current;
        }
        return res;
    }
};