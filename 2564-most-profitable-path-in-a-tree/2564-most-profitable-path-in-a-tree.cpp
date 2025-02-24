class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> tree(n);  // Adjacency list

        // Step 1: Build the tree
        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        vector<int> bobTime(n, -1); // Stores when Bob reaches each node
        vector<int> pathToRoot;     // Stores Bobâs path from `bob` to `0`

        // Step 2: DFS to find Bobâs path and track time to each node
        function<bool(int, int, int)> findBobPath = [&](int node, int parent, int time) {
            if (node == bob) {
                bobTime[node] = time;
                pathToRoot.push_back(node);
                return true;
            }
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue; // Avoid backtracking
                if (findBobPath(neighbor, node, time + 1)) {
                    bobTime[node] = time;
                    pathToRoot.push_back(node);
                    return true;
                }
            }
            return false;
        };

        findBobPath(0, -1, 0); // Start DFS from node 0

        // Step 3: Adjust Bob's time for nodes he passes through
        int bobPathLength = pathToRoot.size();
        for (int i = 0; i < bobPathLength; i++) {
            bobTime[pathToRoot[i]] = i; // Assign exact arrival time
        }

        int maxProfit = INT_MIN;

        // Step 4: DFS for Alice to maximize profit
        function<void(int, int, int, int)> dfsAlice = [&](int node, int parent, int time, int profit) {
            if (bobTime[node] == -1 || time < bobTime[node]) {
                profit += amount[node]; // Alice gets full amount
            } else if (time == bobTime[node]) {
                profit += amount[node] / 2; // Alice and Bob split amount
            }
            // If Bob arrives earlier, Alice gets nothing

            bool isLeaf = true;
            for (int neighbor : tree[node]) {
                if (neighbor == parent) continue;
                isLeaf = false;
                dfsAlice(neighbor, node, time + 1, profit);
            }

            if (isLeaf) { // If Alice reaches a leaf, update max profit
                maxProfit = max(maxProfit, profit);
            }
        };

        dfsAlice(0, -1, 0, 0); // Start DFS for Alice from node 0
        return maxProfit;
    }
};
