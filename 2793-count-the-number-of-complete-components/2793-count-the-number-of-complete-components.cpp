class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &temp){
        temp.push_back(node);
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0) dfs(it,adj,vis,temp);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int x=adj[i].size();
                vector<int> temp;
                dfs(i,adj,vis,temp);
                bool flag=true;
                for(auto it:temp){
                    if(adj[it].size()!=temp.size()-1) {
                        flag=false;
                        break;
                    }
                }
                if(flag) cnt++;
            }
        }
        return cnt;
    }
};