class Solution {
public:
    vector<int> diStringMatch(string s) {
         int left = count(s.begin(), s.end(), 'D'), right = left;
        vector<int> res = {left};
        for (char &c : s)
            res.push_back(c == 'I' ? ++right : --left);
        return res;
    }
};