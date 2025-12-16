class Solution {
public:
    int bound;  
    unordered_map<int, int> remap; 
    unordered_set<int> black;       

    Solution(int n, vector<int>& blacklist) {
        bound = n - blacklist.size();

        for (int b : blacklist) {
            black.insert(b);
        }

        int swapTarget = n - 1;

        for (int b : blacklist) {
            if (b < bound) {
    
                while (black.count(swapTarget)) {
                    --swapTarget;
                }
                remap[b] = swapTarget;  
                --swapTarget;
            }
        }
    }

    int pick() {
        int randIdx = rand() % bound;
        return remap.count(randIdx) ? remap[randIdx] : randIdx;
    }
};