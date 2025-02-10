class Solution {
public:
    string clearDigits(string s) {
        string res;

        for(int i = 0; i<s.size(); i++){
            if(s[i]<='9' && s[i]>='0' && !res.empty()){
                res.pop_back();
                continue;
            }
            res = res + s[i];
        }
        return res;
    }
};