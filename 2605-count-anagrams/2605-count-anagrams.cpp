class Solution {
public:
    int countAnagrams(string s) {
        int n = s.size();

        int space = 0;
        for (auto e : s) {
            if (isspace(e)) {
                space++;
            }
        }
        int words = space + 1;

        vector<long long> perm(words);

        int i = 0;
        int pI = 0;
        for (int j = 0; j < n; j++) {
            if (isspace(s[j])) {
                string word = s.substr(i, j - i);
                i = j + 1;
                perm[pI++] = findPerm(word);
            }
        }

        if (i < n) {
            perm[pI++] = findPerm(s.substr(i));
        }

        const long long MOD = 1e9 + 7;
        long long anagrams = 1;
        for (auto p : perm) {
            anagrams = (anagrams * p) % MOD;  
        }

        return (int)anagrams;
    }

    int findPerm(string word) {
        const long long MOD = 1e9 + 7;
        unordered_map<char, int> mp;
        for (auto e : word) {
            mp[e]++;
        }

        int len = word.size();

        long long allPerms = factorial(len, MOD); 

        for (auto e : mp) {
            int freq = e.second;
            allPerms = (allPerms * modInverse(factorial(freq, MOD), MOD)) % MOD;  
        }

        return allPerms;
    }

    long long factorial(int x, long long MOD) {
        long long res = 1;
        for (int i = 2; i <= x; i++) {
            res = (res * i) % MOD;
        }
        return res;
    }

    long long modPow(long long a, long long b, long long MOD) {
        long long res = 1;
        a %= MOD;
        while (b > 0) {
            if (b % 2 == 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return res;
    }


    //Fermat theorem btw
    long long modInverse(long long a, long long MOD) {
        return modPow(a, MOD - 2, MOD);  
    }
};
