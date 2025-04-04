class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        set<int> st(v.begin(), v.end()); // Store all elements in a set
        int maxseq = 0;

        for (int num : v) {
            if (st.find(num - 1) == st.end()) { // Only start from the smallest in a sequence
                int cur_num = num;
                int seq = 1;

                while (st.find(cur_num + 1) != st.end()) {
                    cur_num++;
                    seq++;
                }
                maxseq = max(maxseq, seq);
            }
        }
        return maxseq;
    }
};
