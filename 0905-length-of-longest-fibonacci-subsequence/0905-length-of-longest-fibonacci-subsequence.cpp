class Solution {
public:
    int binary_search(vector<int>& arr,int l,int r,int val) {
        while(l<=r) {
            int m=(l+r)/2;
            if(arr[m]==val) return m;
            else if(arr[m]>val) r=m-1;
            else l =m+1;
        }
        return -1;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int res = 0, n = arr.size();
        for(int i=0;i<n-2;i++) {
            for(int j=i+1;j<n-1;j++) {
                int val1 = arr[i] ,val2 = arr[j],count=2 , m = binary_search(arr,j+1,n-1,val1+val2);
                while(m!=-1) {
                    count++;
                    int temp =val1;
                    val1=val2;
                    val2=temp+val1;
                    m = binary_search(arr,m+1,n-1,val1+val2);
                }
                if(count>2) res = max(res,count);
            }
        }
        return res;
    }
};