class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time = 0;
        for (int e : left) {
            time = max(time, e);
        }
        for (int e : right) {
            time = max(time, n - e);
        }
        return time;
    }
};
