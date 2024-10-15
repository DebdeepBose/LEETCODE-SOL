class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> st;
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                st.insert(i);
                st.insert(n / i);
            }
        }
        st.insert(n);
        if (k <= st.size()) {
            auto it = st.begin();
            advance(it, k - 1);
            return *it;
        } else {
            return -1;
        }
    }
};
