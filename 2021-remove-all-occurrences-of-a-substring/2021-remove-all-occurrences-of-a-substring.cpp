class Solution {
public:
    string removeOccurrences(string s, string part) {
        int iter = s.find(part); 
        while(iter != -1){
            s.erase(s.begin()+iter, s.begin()+iter + part.size());
            iter = s.find(part); 
        }
        return s;
    }
};