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
        // Yeah like what if f = "abc" & s = "def", nothings common here so
        // might as well store primaryMerge1 = "abcdef". Sure we will do stuff
        // to check if they haveanythin common or not but if they dont we
        // simpley return primaryMerge1
        string primaryMerge1 = f + s;
        for (int i = min(m, n) - 1; i >= 0; i--) {
            // Its like comparung suffix of first string and rpefix of seocnd
            // stirng and whatever we find comoon(if we do), we just update
            // primaryMerge1 with that
            if (f.substr(m - i - 1) == s.substr(0, i + 1)) {
                // i mean yeah image f = abc , s = bca see bc is common right?
                // so we take abc cuz we need to cant eally leave 'a' then
                // whatver extra from string s which is a again
                primaryMerge1 = f + s.substr(i + 1);
                // Job done if we found so break
                break;
            }
        }
        // Now we swap, yes what if f = "fgh" and s = "hfg", now if we merger f
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
            // Now u might ask why min? like isnt this else statement executed
            // if they are of equal length? WELL... look "aaa" is same size as
            // "abc", but the question wasntsus to retuen the smallest
            // lexicographically so we cant just return anyone of them like in
            // that case technically we might have returned abc but we shud have
            // return aaa thats why we use min
        }
    }

public:
    string minimumString(string a, string b, string c) {
        // We gon check every permutation and merge them and then
        // check more permutations
        string ab = primaryMerge(a, b);
        string bc = primaryMerge(b, c);
        string ca = primaryMerge(c, a);

        // Cool now u would have gotten ab, bc and ca string merged but but
        // butttt now theres a third string too, we check two strings simply so
        // now we goota include the thirs
        string abc = primaryMerge(ab, c);
        string bca = primaryMerge(bc, a);
        string cab = primaryMerge(ca, b);

        // Cool now we got our stuff, but ya know we gotta return the smallest
        // lexicographically so lets just store in a vector and sort it
        // according to SIZE not lexi btw, like if we owuld have inserted into a
        // set it would ahve given us th lexi smallest which si wrong , size
        // priorty furst

        vector<string> ans;
        ans.push_back(abc);
        ans.push_back(bca);
        ans.push_back(cab);

        sort(ans.begin(), ans.end(), cmp);
        return ans[0];
    }
};