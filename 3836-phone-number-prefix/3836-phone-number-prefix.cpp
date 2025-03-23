class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        sort(numbers.begin(), numbers.end());
        map<int, vector<string>>mp;
        int len = numbers.size();
        for(int i = 0; i < len; i++){
            string s = numbers[i];
            int slen = s.length();
            for(auto &m : mp){
                int tlen = m.first;
                string t = s.substr(0, tlen);
                if(find(m.second.begin(), m.second.end(), t) != m.second.end())
                    return false;
            }
            mp[slen].push_back(s);
        }
        return true;
    }
};