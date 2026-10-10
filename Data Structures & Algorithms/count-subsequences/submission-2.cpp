class Solution {
    vector<vector<int>>dp;
    int dfs(int i , int j, string &s, string &t ) {
        if(i == s.size()) {
            return j == t.size();
            // return cur == t;
        }
        // auto p = make_pair(i , j);
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int ans = dfs(i + 1 , j , s , t );
        if(s[i] == t[j]) {
           
            ans += dfs(i + 1 , j + 1, s , t);
           
        }
        return dp[i][j] = ans;
    }
public:
    int numDistinct(string s, string t) {
        dp = vector<vector<int>>(s.size() , vector<int>(max(t.size() ,s.size()) , -1));
        // reverse(s.begin() , s.end());
        int ans = dfs(0 , 0 , s ,t);
        return ans;
    }
};
