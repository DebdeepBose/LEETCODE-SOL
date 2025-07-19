class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for (auto e : folder) {
            if (ans.empty()) {
                ans.push_back(e);
            } else {
                string prev = ans.back();
                if (e.find(prev) == 0 && e.size() > prev.size() &&
                    e[prev.size()] == '/') {
                    continue;
                } else {
                    ans.push_back(e);
                }
            }
        }
        return ans;
    }
};