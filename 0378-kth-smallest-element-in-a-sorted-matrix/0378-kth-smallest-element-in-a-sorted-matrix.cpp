class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> tmp; 
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i<n; i++){
            for(int p = 0; p < m; p++){
                tmp.push_back(matrix[i][p]);
            }
        }
        sort(tmp.begin(), tmp.end());
        
        return tmp[k-1];
    }
};