class Solution {
public:
    int maximumUnits(vector<vector<int>>& v, int truckSize) {
        priority_queue<pair<int, int>> pq;
        int m = v.size();
        for (auto& e : v) {
            pq.push({e[1], e[0]});
        }
        int units = 0;
        while (!pq.empty()) {
            int boxUnits = pq.top().first;
            int boxes = pq.top().second;
            pq.pop();
            if (truckSize >= boxes) {
                truckSize -= boxes;
                units += (boxes * boxUnits);
            } else {
                units += (truckSize * boxUnits);
                break;
            }
        }
        return units;
    }
};