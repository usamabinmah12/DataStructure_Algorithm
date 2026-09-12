class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<int> sf(n);
        sf[n - 1] = v[n - 1];
        for(int i = n - 2 ; i >= 0 ; i --) {
            sf[i] = max(sf[i + 1] , v[i]);
        }
        int mn = v[0] , ans = 0;
        for(int i = 0 ; i < n ; i++) {
            mn = min(v[i] , mn);
            ans = max(sf[i]  - mn , ans );
        }
        return ans;
    }
};