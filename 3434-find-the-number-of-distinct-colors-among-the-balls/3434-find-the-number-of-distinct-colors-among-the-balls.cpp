class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n, -1);
        unordered_map<int, int> colormp;
        unordered_map<int, int> ballmp;

        for (int i = 0; i < n; i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
            if (ballmp.find(ball) != ballmp.end()) {
                int prevcolor = ballmp[ball];
                colormp[prevcolor]--;
                if (colormp[prevcolor] == 0) {
                    colormp.erase(prevcolor);
                }
            }
            ballmp[ball] = color;
            colormp[color]++;
            res[i] = colormp.size();
        }
        return res;
    }
};