class MRUQueue {
public:
    vector<int> q;
    MRUQueue(int n) {
        for (int i = 1; i <= n; i++) {
            q.push_back(i);
        }
    }
    
    
    int fetch(int k) {
        int n = q.size();

        for (int i = n - 1; i >= k; i--) {
            swap(q[k-1], q[i]);
        }

        return q[n-1];

    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */