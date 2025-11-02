class Solution {
public:
    using ll = long long;
    long long maxProduct(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        ll maxi = (ll)v[n - 1] * (ll)v[n - 2] * 100000LL;
        maxi = max(maxi, (ll)v[0] * -100000LL * v[n - 1]);
        maxi = max(maxi, (ll)v[0] * (ll)v[1] * 100000LL);
        return maxi;
    }
};
