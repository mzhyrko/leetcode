class Solution {
public:
    int maxDifference(string s) {
        int odd=-1;
        int even=INT_MAX;
        vector<int> freq(26);
        for(char c:s) 
            freq[c-'a']++;
        for(int i=0;i<26;i++){
            if(freq[i]%2)
                odd=max(odd,freq[i]);
            else if(freq[i]) 
                even=min(even,freq[i]);
        }
        return odd-even;
    }
};