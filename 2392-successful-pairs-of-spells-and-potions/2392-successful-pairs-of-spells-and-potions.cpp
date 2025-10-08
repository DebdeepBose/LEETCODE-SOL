class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {

        sort(potions.begin(), potions.end());

        int n = spells.size();
        int m = potions.size();

        vector<int> potionPair(n, 0);

        for (int i = 0; i < n; i++) {
            long long need = ceil((double)success / spells[i]);
            int lbIdx = lower_bound(potions.begin(), potions.end(), need) -
                        potions.begin();

            int numOfSuccessfulPotions = m - lbIdx;

            potionPair[i] = numOfSuccessfulPotions;
        }

        return potionPair;
    }
};