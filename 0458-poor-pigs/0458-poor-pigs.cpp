class Solution {
public:
    int poorPigs(int buckets, int poisonTime, int totalTime) {
        int rounds = totalTime / poisonTime + 1;
        return ceil(log10(buckets) / log10(rounds));
    }
};
