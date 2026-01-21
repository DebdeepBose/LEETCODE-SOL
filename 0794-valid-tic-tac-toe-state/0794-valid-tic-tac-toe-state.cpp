class Solution {
public:
    bool validTicTacToe(vector<string>& v) {
        int x = 0;
        int o = 0;
        for (auto e : v) {
            for (int i = 0; i < e.size(); i++) {
                if (e[i] == 'X')
                    x++;
                else if (e[i] == 'O')
                    o++;
            }
        }

        bool ol1 = false, ol2 = false, ol3 = false;
        bool xl1 = false, xl2 = false, xl3 = false;
        if (v[0][0] == 'X' && v[0][1] == 'X' && v[0][2] == 'X')
            xl1 = true;
        if (v[1][0] == 'X' && v[1][1] == 'X' && v[1][2] == 'X')
            xl2 = true;
        if (v[2][0] == 'X' && v[2][1] == 'X' && v[2][2] == 'X')
            xl3 = true;
        if (v[0][0] == 'O' && v[0][1] == 'O' && v[0][2] == 'O')
            ol1 = true;
        if (v[1][0] == 'O' && v[1][1] == 'O' && v[1][2] == 'O')
            ol2 = true;
        if (v[2][0] == 'O' && v[2][1] == 'O' && v[2][2] == 'O')
            ol3 = true;
        if ((xl1 || xl2 || xl3) && (ol1 || ol2 || ol3)) {
            return false;
        }

        // Row check
        if (v[0][0] == 'X' && v[0][1] == 'X' && v[0][2] == 'X' ||
            v[1][0] == 'X' && v[1][1] == 'X' && v[1][2] == 'X' ||
            v[2][0] == 'X' && v[2][1] == 'X' && v[2][2] == 'X') {
            if (o >= x) {
                return false;
            }
        }
        if (v[0][0] == 'O' && v[0][1] == 'O' && v[0][2] == 'O' ||
            v[1][0] == 'O' && v[1][1] == 'O' && v[1][2] == 'O' ||
            v[2][0] == 'O' && v[2][1] == 'O' && v[2][2] == 'O') {
            if (o > x) {
                return false;
            }
        }

        bool oc1 = false, oc2 = false, oc3 = false;
        bool xc1 = false, xc2 = false, xc3 = false;
        if (v[0][0] == 'X' && v[1][0] == 'X' && v[2][0] == 'X')
            xc1 = true;
        if (v[0][1] == 'X' && v[1][1] == 'X' && v[2][1] == 'X')
            xc2 = true;
        if (v[0][2] == 'X' && v[1][2] == 'X' && v[2][2] == 'X')
            xc3 = true;
        if (v[0][0] == 'O' && v[1][0] == 'O' && v[2][0] == 'O')
            oc1 = true;
        if (v[0][1] == 'O' && v[1][1] == 'O' && v[2][1] == 'O')
            oc2 = true;
        if (v[0][2] == 'O' && v[1][2] == 'O' && v[2][2] == 'O')
            oc3 = true;
        if ((xc1 || xc2 || xc3) && (oc1 || oc2 || oc3)) {
            return false;
        }

        
        // Diagonal check
        if (v[0][0] == 'X' && v[1][1] == 'X' && v[2][2] == 'X' ||
            v[0][2] == 'X' && v[1][1] == 'X' && v[2][0] == 'X') {
            if (o == x) {
                return false;
            }
        }
        if (v[0][0] == 'O' && v[1][1] == 'O' && v[2][2] == 'O' ||
            v[0][2] == 'O' && v[1][1] == 'O' && v[2][0] == 'O') {
            if (x != 3) {
                return false;
            }
        }
        if (x > o + 1 || o == 5 || (x == 0 && o > 0) || o > x) {
            return false;
        }
        return true;
    }
};