class Solution {
public:
    bool isPrime(int x) {
        if (x == 2 || x == 3) {
            return true;
        }
        if (x <= 1 || x % 2 == 0 || x % 3 == 0) {
            return false;
        }
        for (int i = 5; i * i < x; i += 6) {
            if (x % i == 0 || x % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& v) {
        unordered_map<int, int> mp;
        for (auto e : v) {
            mp[e]++;
        }
        for (auto e : mp) {
            if (isPrime(e.second)) {
                return true;
            }
        }
        return false;
    }
};