class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if (!st.count(endWord)) return ans;

        unordered_map<string, vector<string>> parents;
        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> curLevel;

            for (int k = 0; k < sz; k++) {
                string word = q.front();
                q.pop();

                string original = word;

                for (int i = 0; i < word.size(); i++) {
                    char orig = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if (!st.count(word)) continue;

                        if (!visited.count(word)) {
                            if (!curLevel.count(word)) {
                                q.push(word);
                                curLevel.insert(word);
                            }
                            parents[word].push_back(original);
                        }

                        if (word == endWord) found = true;
                    }
                    word[i] = orig;
                }
            }

       
            for (auto& w : curLevel) visited.insert(w);
        }

        if (!found) return ans;

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, ans);
        for (auto& p : ans) reverse(p.begin(), p.end());
        return ans;
    }

private:
    void backtrack(const string& word, const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path,
                   vector<vector<string>>& ans) {
        if (word == beginWord) {
            ans.push_back(path);
            return;
        }
        for (auto& par : parents[word]) {
            path.push_back(par);
            backtrack(par, beginWord, parents, path, ans);
            path.pop_back();
        }
    }
};