#define all(x) x.begin(), x.end()
#define pb push_back
class Solution {

    bool match(string& p, string& c) {
        int i;
        for (i = 0; i < p.size(); i++) {
            if (p[i] != c[i])
                return false;
        }

        return c[i] == '/';
    }

public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(all(folder));
        int n = folder.size();

        vector<string> ans;

        ans.pb(folder[0]);
        for (int i = 1; i < n; i++) {
            if (match(ans.back(), folder[i]))
                ;
            else
                ans.pb(folder[i]);
        }

        return ans;
    }
};