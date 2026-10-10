class Solution {
    vector<vector<int>> dp;
    int dfs(int i , int j , string &s1 , string &s2) {
        if(i == s1.size() ) {
            if(j == s2.size()) return 0;
            else return s2.size() - j;
        }
        if(j == s2.size()) {
            return s1.size() - i;
        }
        if(dp[i][j] !=-1) {
            return  dp[i][j];
        }
        int ans = 0;
        if(s1[i] == s2[j]) {
            ans = dfs(i + 1 ,  j + 1 , s1, s2);
        }
        else {
            int cur = 1 + dfs(i , j + 1, s1 , s2);//insert
            cur = min(cur , 1 + dfs(i + 1, j , s1 , s2));//delete
            cur = min(cur , 1 + dfs(i + 1, j + 1 , s1 , s2));//replace
            ans += cur;
        }
        return dp[i][j] =  ans;
    }
public:
    int minDistance(string s1, string s2) {
        if(s2.size() > s1.size()) swap(s1 , s2);
        dp = vector<vector<int>>(s1.size() ,vector<int>(s2.size() + 1 , -1));
        int ans = dfs(0 ,  0,s1, s2);
        return ans;
    }
};
