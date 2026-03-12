class Solution {
private:
    static bool cmp(string& a, string& b) {
        if (a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size();
    }
    string primaryMerge(string f, string s) {
        int m = f.size();
        int n = s.size();
        if (f.find(s) != string::npos) {
            return f;
        }
        if (s.find(f) != string::npos) {
            return s;
        }
        // Yeah like what if f = "abc" & s = "def", nothing's common here so
        // might as well store primaryMerge1 = "abcdef". Sure we will do stuff
        // to check if they have anything common or not but if they don't we
        // simply return primaryMerge1
        string primaryMerge1 = f + s;
        for (int i = min(m, n) - 1; i >= 0; i--) {
            // It's like comparing suffix of first string and prefix of second
            // string and whatever we find common (if we do), we just update
            // primaryMerge1 with that
            if (f.substr(m - i - 1) == s.substr(0, i + 1)) {
                // I mean yeah imagine f = abc , s = bca see bc is common right?
                // so we take abc because we can't really leave 'a' then
                // whatever extra from string s which is a again
                primaryMerge1 = f + s.substr(i + 1);
                // Job done if we found it so break
                break;
            }
        }
        // Now we swap, yes what if f = "fgh" and s = "hfg", now if we merge f
        // + s we get "fghfg" right but if we do s+f aka opposite we get "hfgh"
        // which has a length of 4 so in this case our swapped merge was smaller
        // so we swap got it?
        swap(f, s);

        m = f.size();
        n = s.size();
        string primaryMerge2 = f + s;
        for (int i = min(m, n) - 1; i >= 0; i--) {
            if (f.substr(m - i - 1) == s.substr(0, i + 1)) {
                primaryMerge2 = f + s.substr(i + 1);
                break;
            }
        }
        if (primaryMerge1.size() < primaryMerge2.size()) {
            return primaryMerge1;
        } else if (primaryMerge2.size() < primaryMerge1.size()) {
            return primaryMerge2;
        } else {
            return min(primaryMerge1, primaryMerge2);
            // Now you might ask why min? like isn't this else statement executed
            // if they are of equal length? WELL... look "aaa" is same size as
            // "abc", but the question wants us to return the smallest
            // lexicographically so we can't just return any one of them like in
            // that case technically we might have returned abc but we should have
            // returned aaa that's why we use min
        }
    }

public:
    string minimumString(string a, string b, string c) {
        // We gonna check every permutation and merge them and then
        // check more permutations
        string ab = primaryMerge(a, b);
        string bc = primaryMerge(b, c);
        string ca = primaryMerge(c, a);

        // Cool now you would have gotten ab, bc and ca string merged but but
        // butttt now there's a third string too, we checked two strings simply so
        // now we gotta include the third
        string abc = primaryMerge(ab, c);
        string bca = primaryMerge(bc, a);
        string cab = primaryMerge(ca, b);

        // Cool now we got our stuff, but you know we gotta return the smallest
        // lexicographically so let's just store it in a vector and sort it
        // according to SIZE not lexicographically btw, like if we would have inserted into a
        // set it would have given us the lexicographically smallest which is wrong, size
        // priority first

        vector<string> ans;
        ans.push_back(abc);
        ans.push_back(bca);
        ans.push_back(cab);

        sort(ans.begin(), ans.end(), cmp);
        return ans[0];
    }
};