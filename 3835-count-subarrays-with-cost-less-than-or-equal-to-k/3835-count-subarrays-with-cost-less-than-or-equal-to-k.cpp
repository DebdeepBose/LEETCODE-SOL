class Solution {
public:
    long long countSubarrays(vector<int>& v, long long k) {
        int n = v.size();
        deque<int> minq;
        deque<int> maxq;
        long long c = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            while (!maxq.empty() && v[maxq.back()] <= v[j]) {
                maxq.pop_back();
            }
            while (!minq.empty() && v[minq.back()] >= v[j]) {
                minq.pop_back();
            }
            maxq.push_back(j);
            minq.push_back(j);

            while (i <= j &&
                   1LL * (v[maxq.front()] - v[minq.front()]) * (j - i + 1) >
                       k) {
                if (maxq.front() == i) {
                    maxq.pop_front();
                }
                if (minq.front() == i) {
                    minq.pop_front();
                }
                i++;
            }
            c += j - i + 1;
            j++;
        }
        return c;
    }
};