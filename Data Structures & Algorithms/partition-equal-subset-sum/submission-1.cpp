class Solution {
    vector<vector<int>> dp;
    bool dfs(int i , vector<int> & v , int t) {
        if(t ==  0) {
            return true;
        }
        if(t < 0) return false;
        if(i == v.size()) {
            return false;
        }
        if(dp[i][t] !=- 1) return dp[i][t];

        dp[i][t] = dfs(i + 1 , v , t - v[i]) || dfs(i + 1 , v , t);
        
        return dp[i][t];
    }
public:
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum = accumulate(v.begin() , v.end() , 0LL);
        if(sum & 1) return false;
        dp =  vector<vector<int>> (n , vector<int> (sum / 2 + 1,  -1));
        // dp.resize(n, vector<int>(sum / 2 + 1, -1));

        sum /= 2;
        bool ans = dfs(0 , v , sum);
        return ans;
    }
};
