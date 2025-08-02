class Solution {
public:
    bool canTransform(string st, string end) {
        int i = 0;
        int j = 0;
        int n = st.size();
        int m = end.size();

        if (n != m) {
            return false;
        }

        while (i < n && j < m) {
            while (i < n && st[i] == 'X') {
                i++;
            }
            while (j < m && end[j] == 'X') {
                j++;
            }

            if (i == n && j == m) {
                return true;
            }

            if (i == n || j == m) {
                return false;
            }

            if (st[i] != end[j]) {
                return false;
            }

            if ((st[i] == 'L' && j > i) || (st[i] == 'R' && j < i)) {
                return false;
            }

            i++;
            j++;
        }

        // final check: there shouldn't be non-X characters left
        while (i < n) {
            if (st[i] != 'X') {
                return false;
            }
            i++;
        }
        while (j < m) {
            if (end[j] != 'X') {
                return false;
            }
            j++;
        }

        return true;
    }
};
