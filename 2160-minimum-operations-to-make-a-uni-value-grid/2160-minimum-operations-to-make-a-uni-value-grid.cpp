class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                nums.push_back(grid[i][j]);
                if ((grid[i][j] % x) != (grid[0][0] % x))
                    return -1;
            }
        }
        sort(nums.begin(), nums.end());
        int mid = n * m / 2;
        int count = 0;
        for (int i = 0; i < m * n; i++) {
            if (i < mid)
                count += (nums[mid] - nums[i]) / x;
            if (i >= mid)
                count += (nums[i] - nums[mid]) / x;
        }
        return count;
    }
};