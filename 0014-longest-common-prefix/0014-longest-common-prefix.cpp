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
        int m = v[0].size();
        int n = v.back().size();
        if (!n || !m) {
            return "";
        }
        while (i < m && j < m) {
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