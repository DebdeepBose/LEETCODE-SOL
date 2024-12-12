class Solution {
public:
    long long pickGifts(vector<int>& v, int k) {
        long long s = accumulate(v.begin(), v.end(), 0LL);
        priority_queue<int> pq(v.begin(), v.end());
        for (int i = 0, x = INT_MAX, y; i < k && x > 1; i++) {
            x = pq.top(), y = sqrt(x);
            pq.pop();
            s -= (x - y);
            pq.push(y);
        }
        return s;
    }
};