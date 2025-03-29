class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0, j = 0, cnt = 0;
        bool iMoved = false;
        while (i < target.size()) {
            if (target[i] == source[j]) {
                ++i;
                ++j;
                iMoved = true;
            } else {
                ++j;
            }
            if (j >= source.size()) {
                if (!iMoved) {
                    return -1;
                }
                j = 0;
                ++cnt;
                iMoved = false;
            }
        }

        if (j < source.size() && iMoved) {
            return ++cnt;
        }

        return cnt;
    }
};