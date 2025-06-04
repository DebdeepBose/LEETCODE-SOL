class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& v) {
        for(int i=0;i<v.size()-1;i++){
            for(int j=0;j<v[0].size()-1;j++){
                if(v[i+1][j+1]!=v[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};