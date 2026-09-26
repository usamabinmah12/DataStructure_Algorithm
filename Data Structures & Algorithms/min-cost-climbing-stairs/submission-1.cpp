class Solution {
    
public:
    int minCostClimbingStairs(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        vector<int> res(n,0);
        res[n - 1] = v[n -1];
        for(int i = n - 2 ; i >= 0 ; i--) {
            if(i == n-2) {
                res[i] = v[i]; 
            }
            else {
                res[i]  =v[i] + min(res[i + 1] , res[i + 2]);
            }
        }
        ans = min(res[0] , res[1]);
        return ans;
    }
};
