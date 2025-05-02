class Solution {
public:
    string pushDominoes(string s) {
        int n=s.size(),lastIdx=0,curr=1;
        char last=s[0];
        while(curr<n){
            while(curr<n && s[curr]=='.')curr++;
            if(curr==n){
                if(last=='R'){
                    while(lastIdx!=n)s[lastIdx++]='R';
                }
                break;
            }
            if(last!='R'){
                if(s[curr]=='L'){
                    while(lastIdx!=curr)s[lastIdx++]='L';
                }
            }
            else{
                if(s[curr]=='R'){
                    while(lastIdx!=curr)s[lastIdx++]='R';
                }
                else{
                    int a=lastIdx+1,b=curr-1;
                    while(a<b){
                        s[a++]='R',s[b--]='L';
                    }
                }
            }
            lastIdx=curr;
            last=s[curr++];
        }
        return s;
    }
};
