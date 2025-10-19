class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        unordered_set<string> vis;
        queue<string> q;
        string ans = s;

        q.push(s);
        vis.insert(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            ans = min(ans, cur);

            string added = addToString(cur, a, n);
            if (!vis.count(added)) {
                vis.insert(added);
                q.push(added);
            }

            string rotated = rotateString(cur, b);
            if (!vis.count(rotated)) {
                vis.insert(rotated);
                q.push(rotated);
            }
        }

        return ans;
    }

    string addToString(string s, int a, int n) {
        for (int i = 1; i < n; i += 2) {
            int ch = (s[i] - '0' + a) % 10;
            s[i] = ch + '0';
        }
        return s;
    }

    string rotateString(string s, int b) {
        int n = s.size();
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
        return s;
    }
};
