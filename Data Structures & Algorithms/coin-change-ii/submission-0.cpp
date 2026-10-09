class Solution {
    vector<vector<int>>dp;
    int rec(int i , int t ,vector<int>& c) {
        if(i >= c.size()) {
            return t == 0;
            
        }
        if(t  == 0) {
            return 1;
        }
        if(t < 0) {
            return 0;
        }
        if(dp[i][t] != -1) {
            return dp[i][t];
        }
        int ans = 0;
        for(int j = 0 ; j <= t / c[i] ; j++ ) {
            ans += rec(i + 1 , t - (c[i] * j) , c);
        }
        return dp[i][t] = ans;
    }
public:
    int change(int t, vector<int>& c) {
        dp = vector<vector<int>>(c.size() + 1 , vector<int> (t + 1 , -1));
        int ans = rec(0 , t , c);
        return ans;
    }
};
