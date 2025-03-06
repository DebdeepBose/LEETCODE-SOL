class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> mp(n * n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < v[i].size(); j++) { 
                mp[v[i][j]]++;
            }
        }

        vector<int> ans(2, 0);

        for (int i = 1; i <= n * n; i++) {  
            if (mp[i] == 2) {
                ans[0] = i; 
            } else if (mp[i] == 0) {
                ans[1] = i; 
            }
        }

        return ans;
    }
};
