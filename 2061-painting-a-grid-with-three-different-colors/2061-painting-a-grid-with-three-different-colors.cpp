class Solution {
public:
    vector<vector<int>> list;
    void construct(vector<int>& temp, int pos) {
        if (pos == temp.size())
            list.push_back(temp);
        else {
            for (int i = 0; i < 3; i++) {
                if (pos == 0 || i != temp[pos - 1]) {
                    temp[pos] = i;
                    construct(temp, pos + 1);
                }
            }
        }
    }
    bool valid(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] == v2[i])
                return false;
        }
        return true;
    }
    int colorTheGrid(int m, int n) {
        const unsigned MOD = 1e9 + 7, size = 3 * pow(2, m - 1);
        vector<int> temp(m, -1);
        construct(temp, 0);
        vector<vector<int>> dp(size, vector<int>(n, 0));
        vector<vector<int>> connections(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (valid(list[i], list[j]))
                    connections[i].push_back(j);
            }
        }
        for (int i = 0; i < size; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < size; j++) {
                for (const int& node : connections[j]) {
                    dp[node][i + 1] = (dp[node][i + 1] + dp[j][i]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < size; i++) {
            ans = (ans + dp[i][n - 1]) % MOD;
        }

        return ans;
    }
};