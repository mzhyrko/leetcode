class Solution {
public:
    int maxDifference(string s) {
        vector<int> tmp(26,0);
        vector<int> even;
        vector<int> odd;
        int max_diff = INT_MIN;
        
        for(auto a:s){
            tmp[a-'a']++;
        }

        for(auto a:tmp){
            if(a%2==1){
                odd.push_back(a);
            }
            else if(a%2==0 && a != 0)
                even.push_back(a);
        }
        
        for(int i = 0; i < odd.size(); i++){
            for(int j = 0; j < even.size(); j++){
                if(odd[i] - even[j] >= max_diff){
                    max_diff = odd[i] - even[j];
                }
            }
        }

        return max_diff;
    }
};