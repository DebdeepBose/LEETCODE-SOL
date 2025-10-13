class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (!ans.empty()) {
                string tmp = ans.back();
                sort(tmp.begin(), tmp.end());
                string curWord = words[i];
                sort(curWord.begin(), curWord.end());
                if (tmp == curWord) {
                    continue;
                }
            }

            ans.push_back(words[i]);
        }
        
        return ans;
    }
};