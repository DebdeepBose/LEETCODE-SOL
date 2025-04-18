class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        vector<double> res;
        int n = a.size();
        unordered_map<int, int> del;
        priority_queue<int> lo;
        priority_queue<int, vector<int>, greater<int>> hi;

        for (int i = 0; i < k; i++) lo.push(a[i]);
        for (int i = 0; i < (k / 2); i++) {
            hi.push(lo.top());
            lo.pop();
        }

        for (int i = k; i < n; i++) {
            if (k & 1) res.push_back(lo.top() * 1.0);
            else res.push_back(((double)lo.top() + (double)hi.top()) / 2);

            int r = a[i - k], x = a[i];
            int b = 0;

            if (r <= lo.top()) {
                b--;
                if (r == lo.top()) lo.pop();
                else del[r]++;
            } else {
                b++;
                if (r == hi.top()) hi.pop();
                else del[r]++;
            }

            if (!lo.empty() && x <= lo.top()) {
                lo.push(x);
                b++;
            } else {
                hi.push(x);
                b--;
            }

            if (b < 0) {
                lo.push(hi.top());
                hi.pop();
            } else if (b > 0) {
                hi.push(lo.top());
                lo.pop();
            }

            while (!lo.empty() && del[lo.top()]) {
                del[lo.top()]--;
                lo.pop();
            }
            while (!hi.empty() && del[hi.top()]) {
                del[hi.top()]--;
                hi.pop();
            }
        }

        if (k & 1) res.push_back(lo.top() * 1.0);
        else res.push_back(((double)lo.top() + (double)hi.top()) / 2.0);

        return res;
    }
};
