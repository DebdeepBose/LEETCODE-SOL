class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int> pq(v.begin(),v.end());
        k--;
        while(k!=0){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};