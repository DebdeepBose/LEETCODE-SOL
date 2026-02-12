class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& v) {
        int maxTime = v[0][1];
        int id = v[0][0];
        
        for (int i = 1; i < v.size(); i++) {
            int duration = v[i][1] - v[i - 1][1];
            
            if (duration > maxTime || 
               (duration == maxTime && v[i][0] < id)) {
                maxTime = duration;
                id = v[i][0];
            }
        }
        
        return id;
    }
};