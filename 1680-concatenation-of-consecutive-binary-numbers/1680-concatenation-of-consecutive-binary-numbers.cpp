class Solution {
private:
    int toDeci(string s, const int MOD) {
        long long mul = 1;
        long long ans = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int d = s[i] - '0';
            ans = (ans + (mul * d) % MOD) % MOD;
            mul = (mul * 2) % MOD;
        }

        return (int)ans;
    }

public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        string concat = "";
        for (int i = 1; i <= n; i++) {
            string binary = bitset<32>(i).to_string();
            binary.erase(0, binary.find_first_not_of('0'));
            concat += binary;
        }
        return toDeci(concat, MOD);
    }
};