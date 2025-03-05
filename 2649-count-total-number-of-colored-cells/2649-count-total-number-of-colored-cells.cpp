class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1;
        long long tmp = 0; 

        if(n == 1){
            return 1;
        }
        
        for(int i = 0; i<n-1; i++){
            tmp += 4;
            res += tmp;
        }

        return res;
    }
};