class Solution {
public:
    int maxDistance(string s, int k) {
        int ver = 0, hor = 0, ans = 0;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            switch(ch){
                case 'N':
                    ver++;
                    break;
                case 'S':
                    ver--;
                    break;
                case 'E':
                    hor++;
                    break;
                case 'W':
                    hor--;
                    break;
            }
            
            int md = abs(ver) + abs(hor);
            int wastedDist = i+1 - md;
            int distCanRecoverd = min(k*2 , wastedDist);
            int currDist = md + distCanRecoverd;
            ans = max(ans, currDist);
        }
        return ans;
    }
};