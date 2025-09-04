class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dfx = abs(z - x);
        int dfy = abs(z - y);
        if(dfx<dfy){
            return 1;
        }
        else if(dfy<dfx){
            return 2;
        }
        else if(dfx==dfy){
            return 0;
        }
        return 0;
    }
};