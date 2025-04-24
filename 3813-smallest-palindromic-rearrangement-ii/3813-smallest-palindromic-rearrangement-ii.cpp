class Solution {
public:
    string smallestPalindrome(string s, int K) {
        vector<int> frequency(26, 0);
        for (char ch : s) {
            frequency[ch - 'a']++;
        }
        
        char mid = 0;
        for (int i = 0; i < 26; i++) {
            if (frequency[i] % 2 == 1) {
                mid = 'a' + i;
                frequency[i]--;
                break;
            }
        }
        
        vector<int> halfFreq(26, 0);
        int halfLength = 0;
        for (int i = 0; i < 26; i++) {
            halfFreq[i] = frequency[i] / 2;
            halfLength += halfFreq[i];
        }
        
        long totalPerms = multinomial(halfFreq);
        if (K > totalPerms) return "";
        
        string firstHalf;
        for (int i = 0; i < halfLength; i++) {
            for (int c = 0; c < 26; c++) {
                if (halfFreq[c] > 0) {
                    halfFreq[c]--;
                    long perms = multinomial(halfFreq);
                    if (perms >= K) {
                        firstHalf.push_back('a' + c);
                        break;
                    } else {
                        K -= perms;
                        halfFreq[c]++;
                    }
                }
            }
        }
        
        string revHalf = firstHalf;
        reverse(revHalf.begin(), revHalf.end());
        
        string result;
        if (mid == 0) {
            result = firstHalf + revHalf;
        } else {
            result = firstHalf + mid + revHalf;
        }
        
        return result;
    }

private:
    static const long maxK = 1000001;
    
    long multinomial(vector<int>& counts) {
        int tot = 0;
        for (int cnt : counts) {
            tot += cnt;
        }
        long res = 1;
        for (int i = 0; i < 26; i++) {
            int cnt = counts[i];
            res = res * binom(tot, cnt);
            if (res >= maxK)
                return maxK;
            tot -= cnt;
        }
        return res;
    }

    long binom(int n, int k) {
        if (k > n) return 0;
        if (k > n - k) k = n - k;
        long result = 1;
        for (int i = 1; i <= k; i++) {
            result = result * (n - i + 1) / i;
            if (result >= maxK) return maxK;
        }
        return result;
    }
};