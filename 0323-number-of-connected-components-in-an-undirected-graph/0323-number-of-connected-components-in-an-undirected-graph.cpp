class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        unsigned long long mem[n], *tbl[n];
        fill(&tbl[0], &tbl[n], nullptr);
        int c = 0;

        for (auto& edge : edges) {
            auto ptr1 = tbl[edge[0]];
            auto ptr2 = tbl[edge[1]];
            if (ptr1 == nullptr) {
                if (ptr2 == nullptr) {
                    mem[c] = c;
                    tbl[edge[0]] = &mem[c];
                    tbl[edge[1]] = &mem[c++];
                } else
                    tbl[edge[0]] = ptr2;
            } else if (ptr2 == nullptr)
                tbl[edge[1]] = ptr1;
            else {
                while (*ptr1 > 2000)
                    ptr1 = (unsigned long long*)(*ptr1);
                while (*ptr2 > 2000)
                    ptr2 = (unsigned long long*)(*ptr2);
                if (*ptr1 == *ptr2)
                    continue;
                *ptr2 = (unsigned long long) ptr1;
            }
            --n;
        }
        return n;
    }
};