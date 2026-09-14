class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) {
        int n = v.size();
        long long l = 1 , r = 1e17;
        long long ans = accumulate(v.begin() , v.end() , 0LL) * h;
        while(l <= r) {
            long long mid = (l + r) / 2;
            int cur = 0;
            for(int i = 0 ; i < n ; i++) {
                cur += (v[i] + mid - 1) / mid;
            }
            if(cur <= h) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
