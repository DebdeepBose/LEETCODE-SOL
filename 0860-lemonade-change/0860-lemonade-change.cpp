class Solution {
public:
    bool lemonadeChange(vector<int>& v) {
        if (v[0] != 5) {
            return false;
        }
        int five$ = 0;
        int ten$ = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (v[i] == 5) {
                five$++;
            } else if (v[i] == 10) {
                if (five$ < 1) {
                    return false;
                }
                ten$++;
                five$--;
            } else {
                if ((ten$ < 1 || five$ < 1) || (ten$ == 0 && five$ < 3)) {
                    return false;
                }
                if (ten$ > 0) {
                    ten$--;
                    five$--;
                    continue;
                } else {
                    five$ -= 3;
                }
            }
        }
        return true;
    }
};