class Solution {
private:
    int toDec(string& s) {
        int val = 0;
        for (char c : s) {
            val = (val * 2 + (c - '0')) % 5;
        }
        return val;
    }

public:
    vector<bool> prefixesDivBy5(vector<int>& v) {
        vector<bool> ans;
        string s = "";
        for (auto e : v) {
            s += to_string(e);
            int x = toDec(s);
            if (x % 5 == 0) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};