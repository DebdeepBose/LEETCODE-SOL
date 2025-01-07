class Solution {
public:
    vector<string> stringMatching(vector<string>& v) {
        int n = v.size();
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && v[j].find(v[i]) != string::npos) {
                    ans.push_back(v[i]);
                    break;
                }
            }
        }
        return ans;
    }
};