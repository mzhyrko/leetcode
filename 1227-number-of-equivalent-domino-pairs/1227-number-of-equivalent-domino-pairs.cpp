class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        int count[100] = {0};
        int result = 0;

        for (auto& domino : dominoes) {
            int normalized =
                min(domino[0], domino[1]) * 10 + max(domino[0], domino[1]);

            result += count[normalized];

            count[normalized]++;
        }

        return result;
    }
};
