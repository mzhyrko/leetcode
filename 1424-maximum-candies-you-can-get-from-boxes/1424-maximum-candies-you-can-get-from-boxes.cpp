class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans=0;
        unordered_map<int, bool> foundNtaken;
        queue<int> foundboxes;
        for (int box : initialBoxes) {
            foundboxes.push(box);
        }

        while(!foundboxes.empty()){
            int b = foundboxes.front();
            foundboxes.pop();

            if(status[b]){
                if (foundNtaken[b]) continue;
                ans+= candies[b];
                foundNtaken[b]=true;
                for (int k : keys[b]) {
                    status[k] = 1; 
                    if (foundNtaken.find(k) != foundNtaken.end() && foundNtaken[k] == false) {
                        foundboxes.push(k); 
                    }
                }
                for(int c: containedBoxes[b]){
                    if (foundNtaken.find(c) == foundNtaken.end()) {
                        foundboxes.push(c);
                    }
                }
            } 

            else{
                foundNtaken[b]=false;
            }
        }

        return ans;
    }
};