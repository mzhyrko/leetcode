class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        const int n = colors.size();

        int groupsFound = 0;

        int maxWindowAtStart = 1;

        int left = 0;
        for (int right = 1; right < n; right++) {
            if (colors[right] != colors[right - 1]) {

                if (right - left + 1 == k) {

                    groupsFound++;

                    left++;
                }

                if (left == 0) {

                    maxWindowAtStart++;
                }
            } else {

                left = right;
            }
        }

        if (colors[n - 1] != colors[0]) {
            int maxWindowAtEnd = n - left;
            int groupsInCombinedRange =
                max(0, maxWindowAtStart + maxWindowAtEnd - k + 1);

            groupsFound += min(groupsInCombinedRange, maxWindowAtStart);
        }

        return groupsFound;
    }
};