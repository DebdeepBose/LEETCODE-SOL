class Solution {
public:
    int similarPairs(vector<string>& v) {
        unordered_map<string, int> mp;
        for (auto& s : v) {
            sort(s.begin(), s.end());
            string newS = "";
            for (auto& ch : s) {
                if (newS.empty()) {
                    newS += ch;
                } else if (newS.back() != ch) {
                    newS += ch;
                }
            }
            mp[newS]++;
        }
        int ans = 0;
        for (auto& k : mp) {
            int x = k.second;
            if (x > 1) {
                ans += x * (x - 1) / 2;
            }
        }
        return ans;
    }
};

// 2 -> 2
// 3 -> 3
// 4 -> 4