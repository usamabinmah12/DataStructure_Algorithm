class Solution {
    vector<vector<int>> dp;
    int bfs(int i ,int j , int val ,vector<vector<int>>& v ) {
        if(i < 0 or i >= v.size() or j < 0 or j >= v[0].size()) {
            return 0;
        }
        if(val >= v[i][j]) {
            return 0;
        }
        if(dp[i][j] !=-1) {
            return dp[i][j];
        }
        int ans = 0;
        if(v[i][j] > val) {
            ans = 1 + bfs(i + 1 ,j , v[i][j] , v);
            ans = max(ans , 1 + bfs(i - 1 ,j , v[i][j] , v));
            ans = max(ans , 1 + bfs(i  ,j + 1 , v[i][j] , v));
            ans = max(ans , 1 + bfs(i ,j - 1, v[i][j] , v));
        }
        // else return 0;
        return dp[i][j] =  ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& v) {
        dp = vector<vector<int>>(v.size() , vector<int>(v[0].size(), -1));
        int ans =0;
        for(int i = 0  ; i < v.size() ; i++) {
            for(int j = 0 ; j < v[0].size() ; j++) {
             ans = max(ans  ,bfs(i , j , -1 ,v));   
            }
        }
         
        return ans;
    }
};
