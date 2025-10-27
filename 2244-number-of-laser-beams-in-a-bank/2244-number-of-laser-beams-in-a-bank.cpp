class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        int m = bank.size();
        int n = bank[0].size();
        int laserBeam = 0;

        vector<int> levelLasers(m, 0);

        for (int i = 0; i < m; i++) {
            int levelCount = 0;
            for (int j = 0; j < n; j++) {
                if (bank[i][j] == '1') {
                    levelCount++;
                }
            }
            levelLasers[i] = levelCount;
        }

        int i = 0;
        int j = 1;
        while (j < m) {
            if (levelLasers[j] > 0) { 
                laserBeam += (levelLasers[j] * levelLasers[i]);
                i = j;
            }
            j++;
        }

        return laserBeam;
    }
};
