#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& v) {
        int storeprev = v[0];
        for (int i = 1; i < v.size(); i++) {
            int curr = v[i];
            v[i] = curr ^ storeprev;
            storeprev = curr;
        }
        return v;
    }
};
