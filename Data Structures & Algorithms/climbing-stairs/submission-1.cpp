class Solution {
    vector<int> dp;
    int rec(int n) {
        if(n == 0) {
            return 1;
        }
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        cout << n << ' ';
        ans = rec(n - 2) + rec(n - 1);
        return dp[n] = ans;
    }
public:
    int climbStairs(int n) {
        dp = vector<int>(n + 1 , -1);
        int ans = rec(n);
        return ans;
    }
};
