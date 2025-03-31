class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n = cost.size();
        vector<int> res(n, 0);
        res[0] = cost[0];
        for (int i = 1; i < n; i++)
            res[i] = min(res[i - 1], cost[i]);
        return res;
    }
};