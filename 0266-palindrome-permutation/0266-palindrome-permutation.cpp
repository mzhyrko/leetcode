class Solution {
public:
    bool canPermutePalindrome(string s) {
        int odd_count = 0;
        vector<int> tmp (26, 0);

        for(int i = 0; i<s.size(); i++){
            tmp[s[i]-'a']++;
        }

        for(int i = 0; i<26; i++){
            if(tmp[i]%2==1){
                odd_count++;
            }
        }

        if(odd_count > 1){
            return false;
        }
        return true;
    }
};