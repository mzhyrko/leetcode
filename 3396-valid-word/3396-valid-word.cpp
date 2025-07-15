class Solution {
public:
    bool isValid(string word) {
        bool vowel = false;
        bool cons = false;

        for(auto ch: word){
            if((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U')){
                vowel = true;
            }else if(((ch > 'a' && ch <= 'z') || (ch > 'A' && ch <= 'Z'))){
                cons = true;
            }

            if(ch == '$' || ch == '@' || ch == '#')
                return false;
        }
        
        if(vowel && cons && word.size() > 2)
            return true;

        return false;
    }
};