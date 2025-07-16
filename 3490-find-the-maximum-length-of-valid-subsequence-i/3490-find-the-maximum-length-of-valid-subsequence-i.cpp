class Solution {
public:
    int maximumLength(vector<int>& nums) {
 
        vector<int> odd;
        vector<int> even;
        vector<int> evenOdd;
        int n=nums.size();
       
        for(int i=0;i<n;i++){
                if(nums[i]%2==0){
                    even.push_back(nums[i]);
                }else{
                    odd.push_back(nums[i]);
                }
                if(i!=0 && (evenOdd.back()%2 == 0 && nums[i]%2!=0)){
                        evenOdd.push_back(nums[i]);
                }else if(i==0){
                    evenOdd.push_back(nums[0]);
                }else if(i!=0 && (evenOdd.back()%2 != 0 && nums[i]%2==0)){
                    evenOdd.push_back(nums[i]);
                }

        }
            return max(evenOdd.size(),max(even.size(), odd.size()));
    }
};