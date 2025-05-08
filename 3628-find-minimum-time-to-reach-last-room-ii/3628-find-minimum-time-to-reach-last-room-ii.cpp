class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>>distance(n, vector<int>(m,INT_MAX));
        priority_queue<pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>>, greater<pair<pair<int,int>,pair<int,int>>>>q;
        q.push({{0,0},{0,0}});
        distance[0][0]=0;
        int dx [] ={0,0,1,-1};
        int dy [] ={1,-1,0,0};
        while(q.size()>0){
            auto it = q.top(); q.pop();
            int dis = it.first.first;
            int f = it.first.second;
            int y = it.second.second;
            int x = it.second.first;
            if(x==n-1&&y==m-1)
            return dis;
            for(int i=0;i<4;i++){
                int x1 = x+dx[i];
                int y1 = y+dy[i];

                if(x1>=0&&x1<n&&y1>=0&&y1<m){
                    int updatedDis = max(moveTime[x1][y1],dis);
                    updatedDis += f==0? 1:2;
                    if(distance[x1][y1] > updatedDis){
                        distance[x1][y1]= updatedDis;
                        int f1=!f;
                        q.push({{updatedDis,f1},{x1,y1}});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<distance[i][j]<<" ";
            }
            cout<<endl;
        }
        return -1;
    }
};