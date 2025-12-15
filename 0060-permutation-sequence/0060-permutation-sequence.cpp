class Solution {
public:
    string getPermutation(int n, int k) {
        char c = '1';
        string s = "";
        for (int i = 0; i < n; i++) {
            s += c;
            c++;
        }
        if (k == 1) {
            return s;
        }
        vector<string> v;
        vector<bool> used(n, false);
        bktrk(s, used, "", v, n, k);
        return v.back();
    }

private:
    void bktrk(string& s, vector<bool>& used, string tmp, vector<string>& v,
               int n, int k) {
        if (v.size() == k)
            return;

        if (tmp.size() == n) {
            v.push_back(tmp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;

            used[i] = true;
            tmp.push_back(s[i]);

            bktrk(s, used, tmp, v, n, k);

            tmp.pop_back();
            used[i] = false;
        }
    }
};