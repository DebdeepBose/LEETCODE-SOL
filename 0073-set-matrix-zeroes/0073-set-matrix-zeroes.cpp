class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        bool fcol = false;
        bool frow = false;

        int n = v.size();
        int m = v[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 0) {
                    if (i == 0) {
                        frow = true;
                    }
                    if (j == 0) {
                        fcol = true;
                    }
                    v[i][0] = 0;
                    v[0][j] = 0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(v[i][0]==0 || v[0][j] ==0 ){
                    v[i][j]=0;
                }
            }
        }

        if(frow){
            for(int j=0;j<m;j++){
                v[0][j]=0;
            }
        }

        if(fcol){
            for(int i=0;i<n;i++){
                v[i][0]=0;
            }
        }

        
    }
};