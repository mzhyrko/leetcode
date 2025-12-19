class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        for(int i = 1; i<=n; i++){
            res.push_back("Push");
            if(find(target.begin(), target.end(), i) == target.end()){
                res.push_back("Pop");
            } 
            if(target[target.size()-1] == i){
                return res;
            }
        }
        return res;
    }
};