class Solution {
private:
    void bktrk(char ch, string& s, vector<char>& c, int i,
               vector<string>& store, int n) {

        if (s.size() == n) {
            store.push_back(s);
            return;
        }

        if (i == 3) {
            return;
        }

        if (c[i] != ch) {
            char prev = ch;
            ch = c[i];

            s += c[i];
            bktrk(ch, s, c, 0, store, n);  
            s.pop_back();

            ch = prev;
        }

        bktrk(ch, s, c, i + 1, store, n);
    }

public:
    string getHappyString(int n, int k) {

        long long totalStrings = 3 * pow(2, n - 1);
        if (k > totalStrings) {
            return "";
        }

        vector<char> c = {'a', 'b', 'c'};
        vector<string> store;
        string s = "";

        long long block = pow(2, n - 1);
        char start = 'a';

        while (k > block) {
            k -= block;
            start++;
        }

        s += start;

        bktrk(start, s, c, 0, store, n);

        return store[k - 1];
    }
};