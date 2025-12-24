class Solution {
public:
    int minimumBoxes(vector<int>& v, vector<int>& cap) {
        sort(cap.rbegin(), cap.rend());
        int c = 0;
        int apples = accumulate(v.begin(), v.end(), 0);
        for (int i = 0; i < cap.size(); i++) {
            if (apples > 0) {
                apples -= cap[i];
                c++;
            }
            if (apples <= 0) {
                break;
            }
        }
        return c;
    }
};