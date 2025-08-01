class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if (n == 0) {
            return "0";
        }

        string ans;

        if ((n < 0) ^ (d < 0)) {
            ans += "-";
        }

        long long num = abs((long long)n);
        long long den = abs((long long)d);

        ans += to_string(num / den);
        long long rem = num % den;

        if (rem == 0) {
            return ans;
        }

        ans += ".";

        unordered_map<long long, int> seen;

        while (rem != 0) {
            if (seen.find(rem) != seen.end()) {
                ans.insert(seen[rem], "(");
                ans += ")";
                break;
            }

            seen[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
        }

        return ans;
    }
};
