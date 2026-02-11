class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        if (v.size() == 1) {
            return v[0];
        }
        sort(v.begin(), v.end());
        string pref = "";
        int i = 0;
        int j = 0;
        if (v[0].empty() || v.back().empty()) {
            return "";
        }
        while (i < v[0].size() && j < v.back().size()) {
            if (v[0][i] == v.back()[j]) {
                pref += v[0][i];
                i++;
                j++;
            } else {
                break;
            }
        }
        return pref;
    }
};