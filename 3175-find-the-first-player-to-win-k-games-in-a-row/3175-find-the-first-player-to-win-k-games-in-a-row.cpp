class Solution {
public:
    int findWinningPlayer(vector<int>& v, int k) {
        int n = v.size();
        if (k >= n) {
            int maxi = *max_element(v.begin(), v.end());
            int idx = find(v.begin(), v.end(), maxi) - v.begin();
            return idx;
        }
        deque<int> dq(v.begin(), v.end());
        int front = dq.front();
        dq.pop_front();
        int second = dq.front();
        dq.pop_front();
        int prevMax = max(front, second);
        dq.push_front(prevMax);
        dq.push_back(min(front, second));
        int c = 1;
        if (c == k) {
            if (v[0] > v[1]) {
                return 0;
            } else {
                return 1;
            }
        }
        int store = -1;
        while (true) {
            int front = dq.front();
            dq.pop_front();
            int second = dq.front();
            dq.pop_front();
            int curMax = max(front, second);
            if (curMax > prevMax) {
                prevMax = curMax;
                c = 1;
            } else if (curMax == prevMax) {
                c++;
                if (c == k) {
                    store = curMax;
                    break;
                }
            }
            dq.push_front(curMax);
            dq.push_back(min(front, second));
        }

        int idx = find(v.begin(), v.end(), store) - v.begin();

        return idx;
    }
};