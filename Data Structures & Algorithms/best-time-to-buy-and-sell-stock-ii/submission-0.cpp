class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0;
        for(int i = p.size() - 1; i >= 0 ; i-- ) {
            int j = i;
            int cur = 0;
            while(j - 1 >= 0 and p[i] > p[j - 1] and p[j] > p[j - 1]) {
               cur = max(cur, p[i] - p[j - 1]);
               j -= 1;
               
            }
            i = j;
            ans += cur;
            
        }
        return ans;
    }
};