class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, -1);
        stack<int> s1, s2;
        vector<int> tmp;

        for (int i = 0; i < n; i++) {
            while (!s2.empty() && v[s2.top()] < v[i]) {
                ans[s2.top()] = v[i];
                s2.pop();
            }
            while (!s1.empty() && v[s1.top()] < v[i]) {
                tmp.push_back(s1.top());
                s1.pop();
            }
            while (!tmp.empty()) {
                s2.push(tmp.back());
                tmp.pop_back();
            }
            s1.push(i);
        }
        return ans;
    }
};