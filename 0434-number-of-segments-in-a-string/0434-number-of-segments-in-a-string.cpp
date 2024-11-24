class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        vector<string> v;
        string w;
        while (ss >> w) {
            v.push_back(w);
        }
        return v.size();
    }
};