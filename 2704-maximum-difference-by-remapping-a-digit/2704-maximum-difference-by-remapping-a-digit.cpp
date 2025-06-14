class Solution {
public:
    int minMaxDifference(int num) {
        string smx = to_string(num);
        int i = 0;
        while (i < smx.size() && smx[i] == '9') i++;
        if (i < smx.size()) {
            char f = smx[i];
            for (char& e : smx) {
                if (e == f) e = '9';
            }
        }
        int numax = stoi(smx);
        string smn = to_string(num);
        char z = smn[0];
        for (char& e : smn) {
            if (e == z) e = '0';
        }
        int numin = stoi(smn);
        return numax - numin;
    }
};
