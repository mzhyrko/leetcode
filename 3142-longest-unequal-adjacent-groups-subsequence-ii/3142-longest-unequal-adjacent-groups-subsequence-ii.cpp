class Solution {
public:
    bool checkHammingOne(string one, string two) {
        int n = one.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (one[i] != two[i]) {
                cnt++;
                if (cnt > 1) {
                    return false;
                }
            }
        }

        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = groups.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int longestSub = 1;
        int longestidx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] &&
                    words[i].length() == words[j].length() &&
                    checkHammingOne(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;

                        if (dp[i] > longestSub) {
                            longestSub = dp[i];
                            longestidx = i;
                        }
                    }
                }
            }
        }

        vector<string> ans;
        int i = longestidx;
        while (parent[i] != -1) {
            ans.push_back(words[i]);
            i = parent[i];
        }
        ans.push_back(words[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};