class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        for (auto e : s) {
            if (e == '*') {
                ans.pop_back();
            }
            else {
                ans.push_back(e);
            }
        }
        return ans;
    }
};