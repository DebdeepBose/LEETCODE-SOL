class Solution {
private:
    long long findCost(long long x, vector<int>& v, vector<int>& p) {
        long long ans = 0;
        for (int i = 0; i < v.size(); i++) {
            ans += 1LL * abs(v[i] - x) * p[i];
        }
        return ans;
    }

public:
    long long minCost(vector<int>& v, vector<int>& p) {
        long long low = ranges::min(v);
        long long high = ranges::max(v);

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long costMid = findCost(mid, v, p);
            long long costLeft = findCost(mid - 1, v, p);
            long long costRight = findCost(mid + 1, v, p);

            if (costLeft < costMid) {
                high = mid - 1;
            } else if (costRight < costMid) {
                low = mid + 1;
            } else {

                return costMid;
            }
        }

        return findCost(low, v, p);
    }
};
