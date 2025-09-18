class Solution {
public:
    int findTheWinner(int n, int k) {
        if (k == 1) {
            return n;
        }
        deque<int> dq;
        for (int i = 1; i <= n; i++) {
            dq.push_back(i);
        }

        while (dq.size() > 1) {
            for (int i = 0; i < k; i++) {
                auto x = dq.front();
                dq.pop_front();
                dq.push_back(x);
            }
            dq.pop_back();
        }

        return dq[0];
    }
};
