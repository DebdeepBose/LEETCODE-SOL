class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int> pq;
        for (auto e : v) {
            pq.push(e);
        }
        while (pq.size() > 1) {
            int fl = pq.top();
            pq.pop();
            int sl = pq.top();
            pq.pop();
            if (fl > sl) {
                pq.push(fl - sl);
            }
        }
        if (pq.empty()) {
            return 0;
        } else {
            return pq.top();
        }
    }
};
