class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0, n = blocks.length(), minOpReq = n;
        for(int i=0;i<k-1;i++)
            if(blocks[i]=='W')
                white++;
        for(int i=k-1;i<n;i++)
        {
            if(blocks[i]=='W')  
                white++;
            
            minOpReq = min(minOpReq,white);

            if(blocks[i-(k-1)]=='W')    
                white--;
        }
        return minOpReq;
    }
};