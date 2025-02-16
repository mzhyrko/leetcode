class Solution {
public:
    bool solve(int index, int n, vector<int>& result, int size,
               vector<bool>& used) {
        if (index >= size) {
            return true;
        }

        if (result[index] != -1) {
            return solve(index + 1, n, result, size, used);
        }

        for (int num = n; num >= 1; num--) {
            if (used[num]) {
                continue;
            }

            result[index] = num;
            used[num] = true;
            if (num == 1) {
                if (solve(index + 1, n, result, size, used)) {
                    return true;
                }
            } else {
                int next_index = index + result[index];
                if (next_index < size && result[next_index] == -1) {
                    result[next_index] = num;
                    if (solve(index + 1, n, result, size, used)) {
                        return true;
                    }
                    result[next_index] = -1;
                }
            }

            used[num] = false;
            result[index] = -1;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {

        int size = 2 * n - 1;
        vector<int> result(size, -1);
        vector<bool> used(n + 1, false);
        solve(0, n, result, size, used);

        return result;
    }
};