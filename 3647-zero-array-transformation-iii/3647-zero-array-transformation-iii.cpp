class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> pq;
        
        vector<int> deltaArray(nums.size() + 1, 0);

        int numsIndex = 0;
        int queriesIndex = 0;
        int operations = 0;

        while (numsIndex < nums.size()) {
            operations += deltaArray[numsIndex];
            while(queriesIndex < queries.size() && queries[queriesIndex][0] <= numsIndex) {
                pq.push(queries[queriesIndex][1]);
                queriesIndex++;
            }

            while(nums[numsIndex] > operations && !pq.empty() && pq.top()  >= numsIndex) {
                int limit = pq.top();
                operations++;
                deltaArray[limit + 1]--;
                pq.pop();
            }


            if (nums[numsIndex] > operations) {
                return -1;
            }
            numsIndex++;
        }

        return pq.size();
    }
};