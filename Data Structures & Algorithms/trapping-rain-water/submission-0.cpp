class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int > sf (n ) , pf(n);
        sf[n -1] = h[n - 1];
        pf[0] =h[0];
        for(int i = 1 ; i < n ; i++) {
            pf[i] = max(h[i] , pf[i - 1]);
        }
        for(int i = n - 2 ; i >= 0 ; i--) {
            sf[i] = max(h[i] , sf[i + 1]);
        }
        int ans = 0;
        for(int i = 1 ; i < n - 1 ; i++) {
            int mn = min(pf[i - 1] , sf[i + 1]);
            ans += max(0 , mn - h[i]);
        }
        return ans;
    }
};
