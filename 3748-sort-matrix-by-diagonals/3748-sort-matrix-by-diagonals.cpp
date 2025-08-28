class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& v) {

        map<int, vector<int>> mp;
        int r = v.size();
        int c = v[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                mp[i - j].push_back(v[i][j]);
            }
        }

        for (auto& e : mp) {
            if (e.first < 0)
                sort(e.second.begin(), e.second.end());
            else
                sort(e.second.rbegin(), e.second.rend());
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                v[i][j] = mp[i - j].front();
                mp[i - j].erase(mp[i - j].begin());
            }
        }

        return v;
    }
};