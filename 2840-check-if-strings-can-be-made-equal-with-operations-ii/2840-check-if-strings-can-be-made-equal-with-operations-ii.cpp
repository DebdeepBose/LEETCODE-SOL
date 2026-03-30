class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char, vector<int>> mp;
        unordered_set<char> st(s2.begin(), s2.end());
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (st.find(s1[i]) == st.end()) {
                return false;
            }
            mp[s1[i]].push_back(i);
            mp[s2[i]].push_back(i);
        }

        for (auto& it : mp) {
            int oddCnt = 0, evenCnt = 0;
            for (auto& num : it.second) {
                num % 2 == 0 ? evenCnt++ : oddCnt++;
            }
            if (oddCnt % 2 != 0 || evenCnt % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};