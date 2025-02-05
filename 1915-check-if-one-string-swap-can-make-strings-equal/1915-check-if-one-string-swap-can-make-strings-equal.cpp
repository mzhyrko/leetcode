class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int counter = 0;

        vector<int> vec1(26,0);
        vector<int> vec2(26,0);

        if(s1.size() != s2.size())
            return false;

        for(int i = 0; i<s2.size(); i++){
            if(s1[i] != s2[i]){
                vec1[s1[i] - 'a']++;
                vec2[s2[i] - 'a']++;
            }

        }

        for(int i = 0; i<26; i++){
            if(vec1[i] == 0){
                continue;
            }
            else{
                if((vec1[i] > 1 || vec2[i] > 1) || vec1[i] != vec2[i]){
                    return false;
                }
                counter++;
            }
        }

        if(counter == 2 || counter == 0){
            return true;
        }
        return false;

    }
};