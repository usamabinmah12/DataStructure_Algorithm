class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n = v.size();
        int cur = 0, sum  = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            cur +=  v[i];
            
            sum = max(sum , cur);
            if(cur < 0) {
                cur = 0;
            }
        }
        return sum;
    }
};
