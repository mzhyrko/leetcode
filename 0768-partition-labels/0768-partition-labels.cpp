class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int>v(26,-1);
        for(int i=0;i<26;i++){
            char ch='a'+i;
            for(int j=n-1;j>=0;j--){
                if(s[j]==ch){
                    v[i]=j;
                    break;
                }
            }
        }
        vector<int>ans;
        int l=0,r=-1;
        for(int i=0;i<n;i++){
            int d=v[s[i]-'a'];
            r=max(r,d);
            
            if(i==r){
                ans.push_back(r-l+1);
                if(r==n-1)break;
                l=r+1,r=v[s[i+1]-'a'];
            }
        }
        return ans;
    }
};