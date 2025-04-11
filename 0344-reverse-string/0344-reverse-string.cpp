class Solution {
public:
    void helper(int left, int right, vector<char>& st) {

        if (left >= right) {
            return;
        }

        swap(st[left], st[right]);

        helper(++left, --right, st);
    }
    void reverseString(vector<char>& st) {
        int n = st.size();
        helper(0, n - 1, st);
    }
};