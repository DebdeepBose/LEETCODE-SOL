class Solution {
public:
    int miceAndCheese(vector<int>& u, vector<int>& v, int k) {
        priority_queue<int> pq;
        int n = u.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            pq.push(u[i] - v[i]);
            sum += v[i];
        }
        
        while (k--) {
            int top = pq.top();
            sum += top;
            pq.pop();
        }
        return sum;
    }
};