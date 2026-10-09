class Solution {
    int res = 0;
    vector<vector<int>>dp;
    int rec(int i, vector<int>&p ,int buy  ) {
        if(i >= p.size()) {
            // res = max(res , cur);
            return 0;
        }
        if(dp[i][buy] !=-1) {
            return dp[i][buy];
        }
        int ans = 0;
        if(buy) {
            
            ans = max( rec(i + 1 , p , 0 ) - p[i],rec(i + 1 , p , 1) );
        }
        else {
            // ans = ;
            ans += max( rec(i + 2 , p , 1) + p[i] ,rec( i + 1 , p  , 0));
        }
        return  dp[i][buy]=  ans;
    }
public:
    int maxProfit(vector<int>& p) {
        res = 0;
        int n = p.size();
        dp = vector<vector<int>>(n + 1, vector<int>(2 , - 1));
        int ans = rec(0 , p , 1 );
        return ans;
    }
};
