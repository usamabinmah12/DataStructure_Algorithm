class Solution {
    vector<vector<int>> dp;
    int n , m;
    int rec(int i , int j , string&s1, string &s2) {
        if(i == n or j == m) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(s1[i] == s2[j]) {
            ans = 1 + rec(i + 1 , j + 1 , s1 , s2);
        }
        else {
            ans = rec(i + 1 , j , s1 , s2);
            ans = max(ans , rec(i , j + 1 , s1 , s2));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
public:
    int longestCommonSubsequence(string s1, string s2) {
     n = s1.size() ,m = s2.size();
       dp = vector<vector<int>> (n  , vector<int>(m  , - 1)) ;
       int ans = rec( 0 , 0 , s1 ,s2);
       return ans;
    }
};
