class Solution {
    int  n;
    vector<int> g;
    vector<vector<int>> dp;
    int rec(int i ,int prev) {
        if(i >= n) {
            return 0;
        }
        if(dp[i][prev] != -1) {
            return dp[i][prev];
        }
       int ans = rec(i + 1 , 0);
       if(prev == 0) {
        ans = max(g[i] + rec(i + 1 , 1) , ans);
       }
    
       return dp[i][prev] = ans;
    }

public:
    int rob(vector<int>& nums) {
       
        n = nums.size();
        g = nums;
        dp = vector<vector<int>>(n,vector<int>(2 , -1));
        // dp.assign(n , vector<int> (2 ,-1));
        int ans = rec(0 , 0);
        return ans;
    }
};
