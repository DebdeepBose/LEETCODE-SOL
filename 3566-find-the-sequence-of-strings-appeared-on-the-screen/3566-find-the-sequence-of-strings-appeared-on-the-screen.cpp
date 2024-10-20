class Solution {
public:
    vector<string> stringSequence(string k) {
        vector<string> ans;
        string s = "";
        for (auto e : k) {
            s += 'a';
            ans.push_back(s);
            while (!s.empty() && s.back() != e) {
                if (s.back() == 'z') {
                    s.back() = 'a';
                } else {
                    s.back() = s.back() + 1;
                }
                ans.push_back(s);
            }
        }
        return ans;
    }
};