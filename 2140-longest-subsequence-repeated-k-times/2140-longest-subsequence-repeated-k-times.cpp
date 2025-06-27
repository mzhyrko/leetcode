class Solution {
public:
    bool check(string rep,string& s){
        int i=0;
        for(char c:s){
            if(i<rep.size() && c==rep[i]){
                i++;
            }
        }
        return i==rep.size();
    }
    string longestSubsequenceRepeatedK(string s,int k){
    
        vector<int>freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }
        string chars="";
        for(int i=25;i>=0;i--){
            if(freq[i]>=k){
                chars+=('a'+i);
            }
        }

        queue<string>q;
        string ans="";
        q.push("");
      
        while(!q.empty()){
            string node=q.front();
            q.pop();
            for(auto it:chars){
                string temp=node+it;
                string rep="";
                for(int i=0;i<k;i++) rep+=temp;
                if(check(rep,s)){
                    if(temp.length()>ans.length()){
                        ans=temp;
                    }
                    q.push(temp);
                }
            }
        }
        return ans;
    }
};
