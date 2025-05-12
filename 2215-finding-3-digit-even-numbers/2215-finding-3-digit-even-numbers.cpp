class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> freq(10,0);

        for(int i:digits){
            freq[i]++;
        }
        for(int i=100;i<1000;i=i+2){
            vector<int> curr(10,0);
            int n=i;
            while(n>0){
                curr[n%10]++;
                n=n/10;
            }
            bool ad=true;
            for(int j=0;j<=9;j++){
                if(freq[j]-curr[j]<0)ad=false;
            }
            if(ad)ans.push_back(i);
        }
        return ans;
    }
};