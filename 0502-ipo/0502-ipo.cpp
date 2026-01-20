class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pf, vector<int>& cap) {
        int n = pf.size();
        vector<pair<int, int>> pr(n);

        for (int i = 0; i < n; i++) {
            pr[i] = {cap[i], pf[i]};
        }

        sort(pr.begin(), pr.end());

        int i = 0;
        priority_queue<int> pq;

        while (k--) {
            while (i < n && pr[i].first <= w) {
                pq.push(pr[i].second);
                i++;
            }

            if (pq.empty()) {
                break;
            }

            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
