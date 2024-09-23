#include <string>
#include <unordered_map>

class Solution {
public:
    bool wordPattern(string s, string r) {
        int c = 0;
        for (auto e : r) {
            if (isspace(e)) {
                c++;
            }
        }
        if (s.size() != c + 1) {
            return false;
        }

        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        string word;
        int i = 0;

        for (int j = 0; j <= r.size(); j++) {
            if (j == r.size() || isspace(r[j])) {
                if (i >= s.size()) {
                    return false;
                }
                char c = s[i];

                if (mp.count(c) > 0) {
                    if (mp[c] != word) {
                        return false;
                    }
                } else {
                    mp[c] = word;
                }

                if (mp2.count(word) > 0) {
                    if (mp2[word] != c) {
                        return false;
                    }
                } else {
                    mp2[word] = c;
                }

                i++;
                word.clear();
            } else {
                word += r[j];
            }
        }

        return true;
    }
};
