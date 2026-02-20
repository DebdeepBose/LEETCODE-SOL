class Solution {
public:
    int findWinningPlayer(vector<int>& v, int k) {
        int curWinner = 0;
        int wins = 0;

        for (int i = 1; i < v.size(); i++) {
            if (v[i] > v[curWinner]) {
                curWinner = i;
                wins = 1;
            } else {
                wins++;
            }

            if (wins == k) {
                return curWinner;
            }
        }

        return curWinner;
    }
};