class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char, int> mp;
        for (auto e : brokenLetters) {
            mp[e]++;
        }

        int space = 0;

        for (auto e : text) {
            if (isspace(e)) {
                space++;
            }
        }

        if (space == 0) {
            for (auto e : text) {
                if (mp[e] > 0) {
                    return 0;
                }
            }
        }

        int j = 0;
        int n = text.size();

        while (j < n) {
            if (mp[text[j]] > 0) {
                while (!isspace(text[j])) {
                    if (j == n - 1) {
                        return space;
                    }
                    j++;
                }
                space--;
            }
            j++;
        }

        return space + 1;
    }
};