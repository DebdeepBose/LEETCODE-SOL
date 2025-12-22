class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> st;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                return true;
            }
            string curr = s.substr(i, 2);
            string rev = "";
            rev += s[i + 1];
            rev += s[i];

            if (st.count(rev)) {
                return true;
            }

            st.insert(curr);
        }

        return false;
    }
};
