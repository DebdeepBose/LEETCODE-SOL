class Solution {
public:
    vector<int> countMentions(int n,
                              vector<vector<string>>& v) {

        ranges::sort(v, {},
                     [](auto& e) { return pair(stoi(e[1]), e[0][2]); });

        vector<int> ans(n);
        vector<int> on(n);

        for (auto& e : v) {
            int cur = stoi(e[1]);
            string& mention = e[2];

            if (e[0][0] == 'O') {
                on[stoi(mention)] = cur + 60;
            } 
            else if (mention[0] == 'A') {
                for (auto& f : ans) {
                    f++;
                }
            } 
            else if (mention[0] == 'H') {
                for (int i = 0; i < n; i++) {
                    if (on[i] <= cur) ans[i]++;
                }
            } 
            else {
                for (const auto& part : mention | ranges::views::split(' ')) {
                    string s(part.begin() + 2, part.end());
                    ans[stoi(s)]++;
                }
            }
        }
        return ans;
    }
};
