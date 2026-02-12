class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        while (true) {
            int sum = 0;
            while (n != 0) {
                int rem = n % 10;
                sum += rem * rem;
                n /= 10;
            }
            if (sum == 1) {
                return true;
            } else {
                if (st.empty()) {
                    st.insert(sum);
                } else if (!st.empty() && st.find(sum) != st.end()) {
                    return false;
                } else if (!st.empty() && st.find(sum) == st.end()) {
                    st.insert(sum);
                }
            }
            n = sum;
        }
        return true;
    }
};