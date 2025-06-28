class Solution {
public:
    typedef pair<int, int> p;
    vector<int> maxSubsequence(vector<int>& v, int k) {
        priority_queue<p, vector<p>, greater<p>> pq;

        for (int i = 0; i < v.size(); i++) {
            pq.push({v[i], i});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<p> topK;
        while (!pq.empty()) {
            int f = pq.top().second;
            int s = pq.top().first;
            topK.push_back({f,s});
            pq.pop();
        }

        sort(topK.begin(),topK.end());

        vector<int> ans;
        for(auto e : topK){
            ans.push_back(e.second);
        }

        return ans;
    }
};