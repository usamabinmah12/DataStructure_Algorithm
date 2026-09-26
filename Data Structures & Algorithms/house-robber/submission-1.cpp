class Solution {
    int  n;
    vector<int> g;
   vector<int>dp;
    int rec(int i ) {
        if(i >= n) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
       int ans = rec(i + 1);
    
       ans = max(g[i] + rec(i + 2) , ans);
  
    
       return dp[i] = ans;
    }

public:
    int rob(vector<int>& nums) {
       
        n = nums.size();
        g = nums;
        dp =  vector<int>(n,-1);
        // dp.assign(n , vector<int> (2 ,-1));
        int ans = rec(0);
        return ans;
    }
};
