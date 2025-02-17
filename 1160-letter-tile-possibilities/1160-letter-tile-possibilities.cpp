class Solution {
public:
    unordered_set<string> isString;
    int helper(string &tiles,int idx){
        if(idx==tiles.size()){
            if(isString.find(tiles)==isString.end()){
                isString.insert(tiles);
                return 1;
            }
            return 0;
        }
        int count=0;
        for(int i=idx;i<tiles.size();i++){
            swap(tiles[i],tiles[idx]);
            count+=helper(tiles,idx+1);
            swap(tiles[i],tiles[idx]);
        }
        return count;
    }
    int generate(string &tiles,string str,int idx){
        if(idx==tiles.size()){
            return helper(str,0);
        }
        return generate(tiles,str+tiles[idx],idx+1) + generate(tiles,str,idx+1);
    }
    int numTilePossibilities(string &tiles) {
        int count=0;
        count+=generate(tiles,"",0);
        return count-1;
    }
};