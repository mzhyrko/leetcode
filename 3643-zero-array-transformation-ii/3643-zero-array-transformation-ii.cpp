class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        int qn = queries.size();

        vector<int> lineSweep(n);
        int acc = 0;
        int left = 0;

        for(int i=0; i<=qn; i++)
        {
            while(nums[left] <= acc)
            {
                left++;
                if(left == n) return i;
                acc += lineSweep[left];
            }

            if(i == qn) return -1;

            auto& query = queries[i];
            int inc = query[2];

            if(nums[left] > acc)
            {
                lineSweep[query[0]] += inc;
                if(query[1] + 1 < n) lineSweep[query[1] + 1] -= inc;
        
                if(query[0] <= left && left <= query[1]) acc += inc;
            }

        }

        return -1;
    }
};