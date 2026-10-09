class Solution {
    vector<vector<int> > vis , dp;
    
    int rec(int i , int j , int n , int m) {
        if(i > n or j > m) {
            return 0;
        }
        if(i == n and j == m) {
            return 1;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = rec(i + 1 , j , n , m);
        ans += rec(i , j + 1 ,  n , m);
        dp[i][j] = ans;
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vis = vector<vector<int>>( n + 1, vector<int>(m  + 1, 0));
        dp = vector<vector<int>>( n + 1 , vector<int>(m  + 1, -1));
        int ans = rec( 1, 1 ,  n , m);
        return ans;
    }
};
