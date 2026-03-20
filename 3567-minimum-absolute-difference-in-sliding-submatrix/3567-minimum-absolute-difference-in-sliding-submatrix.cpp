class Solution {
private:
    int findAbsDiff(vector<vector<int>>& v, int k, int f, int s, int a, int b) {
        vector<int> tmp;
        for (int i = f; i < a; i++) {
            for (int j = s; j < b; j++) {
                tmp.push_back(v[i][j]);
            }
        }
        sort(tmp.begin(), tmp.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i] == tmp[i - 1]) {
                continue;
            }
            if (abs(tmp[i] - tmp[i - 1]) < minDiff) {
                minDiff = abs(tmp[i] - tmp[i - 1]);
            }
        }

        return minDiff == INT_MAX ? 0 : minDiff;
    }

public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& v, int k) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < m - k + 1; i++) {
            vector<int> p;
            for (int j = 0; j < n - k + 1; j++) {
                p.push_back(findAbsDiff(v, k, i, j, i + k, j + k));
            }
            ans.push_back(p);
        }
        return ans;
    }
};