class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& iv, vector<int>& newIv) {
        vector<vector<int>> ans;
        int i = 0;

        while (i < iv.size() && iv[i][1] < newIv[0]) {
            ans.push_back(iv[i]);
            i++;
        }

        int ivStart = newIv[0];
        int ivEnd = newIv[1];

        while (i < iv.size() && iv[i][0] <= newIv[1]) {
            ivStart = min(ivStart, iv[i][0]);
            ivEnd = max(ivEnd, iv[i][1]);
            i++;
        }

        ans.push_back({ivStart, ivEnd});

        while (i < iv.size()) {
            ans.push_back(iv[i]);
            i++;
        }

        return ans;
    }
};
