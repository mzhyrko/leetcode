class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        //Initilize all primes from 1 to "right"  
        vector<bool> tmp1(right+1,1);
        vector<int> tmp2;
        
        tmp1[0] = 0;
        tmp1[1] = 0;
        int cur = 0;
        int res1 = 0;
        int res2 = 0;
        int min = INT_MAX;

        if((right - left < 2) || ((right - left == 2) && ((right%2 == 0 || left%2 == 0) || (left %2 == 0 && right%2 == 0)))){
            return {-1, -1};
        }

        for(int i = 2; i<=right/2; i++){
            cur = i;
            while(cur+i <= right){
                cur += i;
                tmp1[cur] = 0;
            }
        }

        for(int i = left; i<=right; i++){
            if(tmp1[i] == 1){
                tmp2.push_back(i);
            }
        }

        for(int i = 0; i<tmp2.size()-1; i++){
            if(tmp2[i+1] - tmp2[i] < min){
                min = tmp2[i+1] - tmp2[i];
                res1 = tmp2[i];
                res2 = tmp2[i+1];
            }
        }

        if((res1 == 0 || res2 == 0) || (res1==0 && res2 == 0)){
            return {-1, -1};
        }

        return {res1, res2};
    }
};