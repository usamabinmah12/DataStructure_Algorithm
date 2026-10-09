class Solution {
    map<pair<int , int> , int>dp;
    int rec(int i ,int cur , vector<int>& v, int t) {
        if(i >= v.size()) {
            return cur == t;
        }
        auto p = make_pair(i , cur);
        if(dp.find(p) != dp.end()) {
            return dp[p];
        }
        int ans =  rec(i  + 1 , cur + v[i] , v , t);
        ans += rec(i + 1, cur - v[i] ,v , t);
        return dp[p] = ans;
    }
public:
    int findTargetSumWays(vector<int>& v, int t) {
        // dp.clear();
        // dp = vector<vector<int>> (v.size() + 1 , vector<int>(1000 * t + 1, -1));
        int ans = rec(0 , 0 , v , t);
        return ans;
    }
};
