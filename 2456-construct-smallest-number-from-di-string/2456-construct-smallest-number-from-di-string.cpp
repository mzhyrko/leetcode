class Solution {
public:
    int n;
    
    bool solve(int idx, string &pattern, string &ans, vector<bool> &used) {
        if (idx >= n + 1) return true; 
        
        for (int i = 1; i <= 9; i++) { 
            if (used[i]) continue;

            used[i] = true;
            if (ans.empty()) {
                ans.push_back(i + '0'); 
                if (solve(idx + 1, pattern, ans, used)) return true;
                ans.pop_back();
            } 
            else if (pattern[idx - 1] == 'I') {
                if (ans.back() < (i + '0')) {
                    ans.push_back(i + '0');
                    if (solve(idx + 1, pattern, ans, used)) return true;
                    ans.pop_back();
                } 
            } 
            else if (pattern[idx - 1] == 'D') {
                if (ans.back() > (i + '0')) {
                    ans.push_back(i + '0');
                    if (solve(idx + 1, pattern, ans, used)) return true;
                    ans.pop_back();
                }
            }
            used[i] = false;
        }
        return false;
    }

    string smallestNumber(string pattern) {
        this->n = pattern.size();
        string ans;
        vector<bool> used(10, false);
        solve(0, pattern, ans, used);
        return ans;
    }
};