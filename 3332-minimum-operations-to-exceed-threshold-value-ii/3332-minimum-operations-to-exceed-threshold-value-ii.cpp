class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int operations = 0;
        
        long long x;
        long long y;

        while (pq.top() < k) {
            x = pq.top(); 
            pq.pop();
            
            y = pq.top(); 
            pq.pop();
            
            pq.push(x * 2 + y);
            operations++;
        }
        
        return operations;
    }
};