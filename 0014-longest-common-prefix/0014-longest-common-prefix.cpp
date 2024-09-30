class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        sort(v.begin(), v.end());
        string f = v.front();
        string l = v.back();
        string ans = "";
        for (int i = 0; i < min(f.size(), l.size()); i++) {
            if (f[i] != l[i]) {
                break;
            }
            ans += f[i];
        }
        return ans;
    }
};