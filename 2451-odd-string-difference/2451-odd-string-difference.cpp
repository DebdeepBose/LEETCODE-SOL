class Solution {
public:
    string oddString(vector<string>& v) {
        vector<vector<int>> d;
        for (auto& s : v) {
            vector<int> tmp;
            for (int i = 1; i < s.size(); i++) {
                tmp.push_back(s[i] - s[i - 1]);
            }
            d.push_back(tmp);
        }
        // First and last compare
        for (int i = 0; i < d[0].size(); i++) {
            if (d[0][i] != d.back()[i]) {
                for (int i = 0; i < d[0].size(); i++) {
                    if (d[0][i] != d[1][i]) {
                        return v[0];
                    } else if (d.back()[i] != d[1][i]) {
                        return v.back();
                    }
                }
            }
        }

        // Since we've come this far it means d[0] isnot the onw we are looking
        // for so we can use it to compare

        for (int i = 1; i < d.size() - 1; i++) {
            for (int j = 0; j < d[0].size(); j++) {
                if (d[i][j] != d[0][j]) {
                    return v[i];
                }
            }
        }
        return "";
    }
};