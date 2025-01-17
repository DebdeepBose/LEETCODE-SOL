class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int> res;
        if (k == 0)
            return res;
        deque<int> w;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            while (!w.empty() && w.front() <= i - k)
                w.pop_front();
            while (!w.empty() && v[w.back()] <= v[i])
                w.pop_back();
            w.push_back(i);
            if (i >= k - 1)
                res.push_back(v[w.front()]);
        }
        return res;
    }
};