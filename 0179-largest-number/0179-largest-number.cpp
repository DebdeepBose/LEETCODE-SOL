class Solution {
public:
    string largestNumber(vector<int>& v) {
        vector<string> temp;
        for (auto e : v) {
            temp.push_back(to_string(e));
        }
        sort(temp.begin(), temp.end(),
             [](string& s1, string& s2) { return s1 + s2 > s2 + s1; });
        string ans;
        for (auto e : temp) {
            ans += e;
        }
        while (ans[0] == '0' && ans.length() > 1) {
            ans.erase(0, 1);
        }
        return ans;
    }
};