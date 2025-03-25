class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& r) {
        if (r.empty()) return false; // Handle empty input case

        vector<pair<int, int>> x, y;
        for (const auto& rect : r) {
            x.emplace_back(rect[0], rect[2]);
            y.emplace_back(rect[1], rect[3]);
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int cnt = 1, cnt1 = 1;
        int maxx = x[0].second;

        for (int i = 1; i < x.size(); i++) {
            if (maxx <= x[i].first) {
                cnt++;
                maxx = x[i].second;
            } else {
                maxx = max(maxx, x[i].second);
            }
        }

        if (cnt >= 3) return true;

        int maxy = y[0].second;
        for (int i = 1; i < y.size(); i++) {
            if (maxy <= y[i].first) {
                cnt1++;
                maxy = y[i].second;  
            } else {
                maxy = max(maxy, y[i].second);
            }
        }

        return (cnt1 >= 3);
    }
};
