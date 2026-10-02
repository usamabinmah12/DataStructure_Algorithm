class Solution {
    vector<long long> dp;
    // long long dfs(int i ,vector<int>& c, int t )  {
    //     if(t == 0) {
    //         return 0;
    //     }
    //     if( i == c.size()) {
    //         return INT_MAX ;
    //     }
        
    //     if(dp[t] != -1) return dp[t];
    //     long long ans = dfs(i + 1, c  , t  ) ;
    //     if(t >= c[i] ) ans = min(ans , 1 + dfs(i , c , t - c[i])) ;
    //     return dp[t] = ans;
    // }
public:
    int coinChange(vector<int>& c, int t) {
        dp = vector<long long>(t + 1, t + 1);
        dp[0] = 0;
        for(int sum = 1 ; sum <= t ; sum++) {
            for(int i = 0  ;  i < c.size() ; i++) {
                if(sum >= c[i]) {
                    dp[sum] = min(dp[sum] , 1 + dp[sum - c[i]]); 
                }
            }
        }
        
        
        return (dp[t] > t) ? -1 : dp[t];
    }
};
