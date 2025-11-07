#include <vector>
#include <numeric>
#include <ranges>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& v, int r, long long k) {
        int n = v.size();
        vector<long long> pre(n);
        pre[0] = v[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + v[i];
        }
        vector<long long> p(n);
        for (int i = 0; i < n; i++) {
            int l = max(0, i - r);
            int rt = min(n - 1, i + r);
            if (l == 0) {
                p[i] = pre[rt];
            } else {
                p[i] = pre[rt] - pre[l - 1];
            }
        }
        long long low = *ranges::min_element(p);
        long long high = ranges::fold_left(p, 0LL, plus<>{}) + k;
        long long ans = low;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (ok(p, r, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

private:
    bool ok(const vector<long long>& p, int r, long long k, long long t) {
        int n = p.size();
        vector<long long> add(n + 1);
        long long cur = 0;
        long long used = 0;
        for (int i = 0; i < n; i++) {
            cur += add[i];
            long long val = p[i] + cur;
            if (val < t) {
                long long need = t - val;
                used += need;
                if (used > k) {
                    return false;
                }
                cur += need;
                if (i + 2 * r + 1 < n) {
                    add[i + 2 * r + 1] -= need;
                }
            }
        }
        return true;
    }
};
