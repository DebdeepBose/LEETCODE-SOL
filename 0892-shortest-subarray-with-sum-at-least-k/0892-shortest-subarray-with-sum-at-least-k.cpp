#include <deque>
class Solution {
public:
    int shortestSubarray(vector<int>& v, int k) {
        int n = v.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + v[i];
        }

        deque<int> dq;
        int ans = n + 1; 

        for (int i = 0; i <= n; i++) {
            
            while (!dq.empty() && pref[i] - pref[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && pref[i] <= pref[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ans <= n ? ans : -1;
    }
};
