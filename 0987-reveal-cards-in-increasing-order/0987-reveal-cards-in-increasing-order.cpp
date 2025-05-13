class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& v) {
        sort(v.rbegin(), v.rend());
        deque<int> dq;
        dq.push_back(v[0]);
        int n = v.size();
        for (int i = 1; i < n; i++) {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(v[i]);
        }
        vector<int> ans(dq.begin(), dq.end());
        return ans;
    }
};