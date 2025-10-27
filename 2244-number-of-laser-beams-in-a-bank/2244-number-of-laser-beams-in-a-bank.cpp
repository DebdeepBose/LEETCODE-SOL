class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        int m = bank.size();
        int n = bank[0].size();
        int laserBeam = 0;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (bank[i][j] == '1') {
                    lookNext(i + 1, m, n, bank, laserBeam);
                }
            }
        }

        return laserBeam;
    }
    void lookNext(int nextI, int m, int n, vector<string>& bank,
                  int& laserBeam) {
        bool foundLevel = false;
        for (int k = nextI; k < m; k++) {
            if (!foundLevel) {
                for (int l = 0; l < n; l++) {
                    if (bank[k][l] == '1') {
                        foundLevel = true;
                        laserBeam++;
                    }
                }
            }
        }
    }
};

// 0 1 1 0 0 1 
// 0 0 0 0 1 0 
// 0 1 0 0 0 0 
// 0 0 1 0 0 0
