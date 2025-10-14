class Solution {
public:
    int maxProfitAssignment(vector<int>& v, vector<int>& p, vector<int>& w) {

        int maxProfit = 0;
        int n = v.size();

        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
            vp.push_back({v[i], p[i]});

        sort(vp.begin(), vp.end());

        int maxP = 0;
        for (auto &pr : vp) {
            maxP = max(maxP, pr.second);
            pr.second = maxP;
        }

        sort(w.begin(), w.end());

        for (int i = 0; i < w.size(); i++) {
            maxProfit += checkWork(w[i], vp);
        }

        return maxProfit;
    }

private:
    int checkWork(int wo, vector<pair<int, int>>& vp) {
        int low = 0, high = vp.size() - 1;
        int maxWork = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (wo >= vp[mid].first) {
                maxWork = vp[mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return maxWork;
    }
};
