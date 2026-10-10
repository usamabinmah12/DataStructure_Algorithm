class Solution {
    vector<vector<int>>dp;
    bool dfs(int i , int j , int k ,string s1, string s2, string s3) {
        if(k == s3.size()) {
            return i == s1.size() and j == s2.size();
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(s1[i] == s2[j] and s2[j] == s3[k]) {
            ans = dfs(i + 1 , j , k + 1 , s1 , s2 , s3);
            ans |= dfs(i , j + 1 ,k + 1 , s1, s2, s3);
        }
        else if(s1[i] == s3[k]) {
            ans = dfs(i + 1 , j , k + 1 , s1 , s2 , s3);
        }
        else if(s2[j] == s3[k]) {
            ans = dfs(i , j + 1 ,k + 1 , s1, s2, s3);
        }
        else {
            return false;
        }
        return dp[i][j] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        dp = vector<vector<int>> (s3.size() ,vector<int>(s3.size(), - 1));
        bool ans = dfs(0 , 0 , 0 , s1 , s2 , s3);
        return ans;
    }
};
