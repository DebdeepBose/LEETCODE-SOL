class Solution {
public:
    int minMaxDifference(int num) {
        int tmp = num;
        string smx = to_string(num);
        bool flag = true;
        int i = 0;
        while (smx[i] == '9') {
            if (i == smx.size()) {
                flag = false;
            }
            i++;
        }
        if (flag) {
            char f = smx[i];
            for (char& e : smx) {
                if (e == f) {
                    e = '9';
                }
            }
        }
        int numax = stoi(smx);
        string smn = to_string(tmp);
        char z = smn[0];
        for (char& e : smn) {
            if (e == z) {
                e = '0';
            }
        }
        int numin = stoi(smn);

        return numax - numin;
    }
};