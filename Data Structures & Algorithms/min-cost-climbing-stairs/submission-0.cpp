class Solution {
    vector<int>gp;
    int n;
    vector<vector<int>> dp;
    int rec(int i , int sum) {
        if(i > n) {
            return 0;
        }
        if(dp[i][sum] != -1) {
            return  dp[i][sum];
        }
        int ans = 0;

        ans = min(rec(i + 1 , sum + gp[i]), rec(i + 2 , sum + gp[i])) + gp[i];
        return dp[i][sum] = ans;
    }
public:
    int minCostClimbingStairs(vector<int>& v) {
        n = v.size();
        gp = vector<int> (n + 2 , 0);
        dp.assign(n + 2 , vector<int>(10000 + 2 , -1));
        
        for(int i = 0 ; i < n ; i++) {
            gp[i + 1] = v[i];
        }
        ++n;
        int ans = 0;
        ans = rec(0 , 0);
        return ans;
    }
};
