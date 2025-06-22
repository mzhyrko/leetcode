class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string a="";
        for (auto i:s){
            if (a.size()==k) {
                ans.push_back(a);
                a="";
            }
            a.push_back(i);
        }
        while (a.size()<k){
            a.push_back(fill);
        }
        ans.push_back(a);
        return ans;
    }
};