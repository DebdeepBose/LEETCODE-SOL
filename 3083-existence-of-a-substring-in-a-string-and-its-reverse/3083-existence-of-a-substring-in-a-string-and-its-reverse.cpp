class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> st;

        for (int i = 0; i < s.size() - 1; i++) {
            st.insert(s.substr(i, 2));
        }

        for (int i = 0; i < s.size() - 1; i++) {
            string rev = "";
            rev += s[i + 1];
            rev += s[i];

            if (st.count(rev)) {
                return true;
            }
        }

        return false;
    }
};
